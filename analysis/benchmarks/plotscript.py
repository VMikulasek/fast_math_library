import subprocess
import json
import matplotlib.pyplot as plt
import numpy as np
from typing import List
from collections import defaultdict
from matplotlib.patches import Rectangle

BENCHMARK_DIR = "../../build/analysis/benchmarks/"

NON_ARRAY_BENCHMARKS = ("accelerated_goniometric_benchmarks",
                        "accelerated_sqrt_benchmarks",
                        "avx_vec2_benchmarks",
                        "avx_vec3_benchmarks",
                        "avx_vec4_benchmarks",
                        "std_goniometric_benchmarks",
                        "std_sqrt_benchmarks",
                        "glm_vec2_benchmarks",
                        "glm_vec3_benchmarks",
                        "glm_vec4_benchmarks",
                        "seq_vec2_benchmarks",
                        "seq_vec3_benchmarks",
                        "seq_vec4_benchmarks")

BENCHMARK_REPETITIONS = 2

def explore_benchmarks() -> List[str]:
    result = subprocess.run(["ls", BENCHMARK_DIR], stdout=subprocess.PIPE, text=True, check=True)
    benchmarks = result.stdout.strip().split("\n")
    return [b for b in benchmarks if b not in ["CMakeFiles", "Makefile", "cmake_install.cmake"]]


def group_benchmarks(benchmarks: List[str]) -> List[List[str]]:
    grouped_array = defaultdict(list)
    grouped_nonarray = defaultdict(list)
    for name in benchmarks:
        parts = name.split("_")
        if len(parts) < 3 or not name.endswith("_benchmarks"):
            continue
        implementation = parts[0]
        operation = parts[1]

        if name in NON_ARRAY_BENCHMARKS:
            grouped_nonarray[operation].append((implementation, name))
        else:
            grouped_array[operation].append((implementation, name))

    result_array = []
    for operation in sorted(grouped_array):
        sorted_group = sorted(grouped_array[operation], key=lambda x: x[0])
        result_array.append([name for _, name in sorted_group])

    result_nonarray = []
    for operation in sorted(grouped_nonarray):
        sorted_group = sorted(grouped_nonarray[operation], key=lambda x: x[0])
        result_nonarray.append([name for _, name in sorted_group])

    return (result_array, result_nonarray)


def run_benchmark(executable: str):
    result = subprocess.run(
        [f"{BENCHMARK_DIR}{executable}",
         f"--benchmark_repetitions={BENCHMARK_REPETITIONS}",
         "--benchmark_format=json"],
        stdout=subprocess.PIPE,
        check=True
    )
    return json.loads(result.stdout)


def extract_data_array(benchmarks):
    grouped = defaultdict(list)

    for record in benchmarks["benchmarks"]:
        grouped[record["per_family_instance_index"]].append(record)
    
    data = []
    for _, records in grouped.items():
        benchmark = {}
        for record in records:
            if not "aggregate_name" in record:
                continue

            record_type = record["aggregate_name"]
            name = record["name"]

            if "mean" in record_type:
                arr_size = int(name.split("/")[1].split("_")[0])
                benchmark["x"] = arr_size
                benchmark["y"] = record["real_time"]
            
            if "stddev" in record_type:
                benchmark["stddev"] = record["real_time"]

        data.append(benchmark)

    return data


def extract_data_nonarray(benchmarks):
    grouped = defaultdict(list)

    for record in benchmarks["benchmarks"]:
        grouped[record["family_index"]].append(record)
    
    data = []
    for _, records in grouped.items():
        benchmark = {}
        for record in records:
            if not "aggregate_name" in record:
                continue

            record_type = record["aggregate_name"]
            name = record["name"]

            if "mean" in record_type:
                operation_name = name.split("_")[1]
                benchmark["x"] = operation_name
                benchmark["y"] = record["real_time"]
            
            if "stddev" in record_type:
                benchmark["stddev"] = record["real_time"]

        data.append(benchmark)

    return data


def configure_graph_array():
    plt.xlabel("Array size")
    plt.ylabel("Time (ns)")
    plt.xscale("log")
    plt.yscale("log")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()


def configure_graph_nonarray(ax, x):
    ax.set_ylabel("Time (ns)")
    ax.set_xticks(np.arange(len(x)))
    ax.set_xticklabels(x, rotation=90)
    ax.legend()
    plt.grid(True)
    plt.tight_layout()


def print_data_array(benchmark_data, color, benchmark_variant, y):
    x = [benchmark["x"] for benchmark in benchmark_data]
    stddev = [benchmark["stddev"] for benchmark in benchmark_data]
    plt.plot(x, y, marker='o', color=color, label=f"{benchmark_variant}")
    plt.fill_between(x, np.array(y) - np.array(stddev), np.array(y) + np.array(stddev), color=color, alpha=0.2, label=f"{benchmark_variant} - standard deviation")


def print_data_nonarray(ax, benchmark_data, color, width, offset, benchmark_variant, y):
    stddev = [benchmark["stddev"] for benchmark in benchmark_data]
    x_coordinates = np.arange(len(y))
    ax.bar(x_coordinates + offset, y, width, label=benchmark_variant, color=color)
    
    for xi, yi, stddevi in zip(x_coordinates, y, stddev):
        rect = Rectangle(
            (xi + offset - 0.5 * width, yi - stddevi),
            width,
            2 * stddevi,
            color='red',
            alpha=0.3
        )
        ax.add_patch(rect)


def log_results(ys, variants, benchmark_operation):
    results = [0] * len(variants)
    results[0] = (len(ys[variants[0]]))

    j = 0
    for variant in variants:
        if variant == variant[0]:
            j += 1
            continue

        for i in range(len(ys[variant])):
            results[j] += ys[variant][i] / ys[variant][0]

        j += 1

    fastest_i = 0
    for i in range(1, len(results)):
        if results[i] < fastest_i:
            fastest_i = i

    results = [0] * len(variants)
    j = 0
    for variant in variants:
        for i in range(len(ys[variant])):
            results[j] += ys[variant][i] / ys[variants[fastest_i]][i]

        j += 1

    for i in range(len(variants)):
        results[i] /= len(ys[variants[0]])

    with open("../../benchmarks_output.txt", "a") as f:
        print(f"\n{benchmark_operation}", file=f)
        print(f"{variants[fastest_i]} - reference", file=f)
        for i in range(len(variants)):
            if i == fastest_i:
                continue

            print(f"{variants[i]} - {results[i]} x slower", file=f)


with open("../../benchmarks_output.txt", "w") as f:
    f.truncate(0)

benchmarks = explore_benchmarks()
array_benchmark_groups, nonarray_benchmark_groups = group_benchmarks(benchmarks)
colors = ("blue", "orange", "green")

i = 0

print("Running array benchmarks [1/2]")

# for benchmark_group in array_benchmark_groups:
#     i += 1
#     benchmark_operation = benchmark_group[0].split("_")[1]
#     print(f"\tRunning {benchmark_operation} benchmarks [{i}/{len(array_benchmark_groups)}]")

#     color_i = 0
#     plt.figure(figsize=(6, 6))
    
#     ys = defaultdict(list)
#     variants = []

#     j = 0
#     for benchmark in benchmark_group:
#         j += 1
#         print(f"\t\tRunning {benchmark} [{j}/{len(benchmark_group)}]")
#         color = colors[color_i]
#         color_i += 1

#         benchmark_json = run_benchmark(benchmark)
#         benchmark_data = extract_data_array(benchmark_json)
        
#         benchmark_variant = benchmark.split("_")[0]
#         variants.append(benchmark_variant)
#         y = [benchmark["y"] for benchmark in benchmark_data]
#         ys[benchmark_variant] = y

#         print_data_array(benchmark_data, color, benchmark_variant, y)

#     log_results(ys, variants, benchmark_operation)
#     configure_graph_array()
#     plt.savefig(f"../../img/{benchmark_operation}.svg")

print("Running non-array benchmarks [2/2]")

i = 0

for benchmark_group in nonarray_benchmark_groups:
    i += 1
    benchmark_operation = benchmark_group[0].split("_")[1]
    print(f"\tRunning {benchmark_operation} benchmarks [{i}/{len(nonarray_benchmark_groups)}]")

    if "vec" in benchmark_operation:
        barwidth = 0.25
        figwidth = 10
    else:
        barwidth = 0.35
        figwidth = 6

    color_i = 0
    _, ax = plt.subplots(figsize=(figwidth, 6))

    ys = defaultdict(list)
    variants = []

    j = 0
    for benchmark in benchmark_group:
        j += 1
        print(f"\t\tRunning {benchmark} [{j}/{len(benchmark_group)}]")
        color = colors[color_i]
        color_i += 1

        benchmark_json = run_benchmark(benchmark)
        benchmark_data = extract_data_nonarray(benchmark_json)

        benchmark_variant = benchmark.split("_")[0]
        variants.append(benchmark_variant)
        x = [benchmark["x"] for benchmark in benchmark_data]
        y = [benchmark["y"] for benchmark in benchmark_data]
        ys[benchmark_variant] = y
        
        offset = (j - ((len(benchmark_group) - 1) * 0.5) - 1) * barwidth
        print_data_nonarray(ax, benchmark_data, color, barwidth, offset, benchmark_variant, y)

    log_results(ys, variants, benchmark_operation)
    configure_graph_nonarray(ax, x)
    if "vec" in benchmark_operation:
        plt.yscale("log")
    
    plt.savefig(f"../../img/{benchmark_operation}.svg")


print("Done")