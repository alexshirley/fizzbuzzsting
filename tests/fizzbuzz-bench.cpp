#include <benchmark/benchmark.h>
#include <fizzbuzz_basic_non_concat.h>
#include <fizzbuzz_composable.h>

static void FB_nonConcat(benchmark::State& state){
    for (auto _ : state)
        for (auto i = 1; i < 101; i++){
            auto res = fizzbuzz_basic_non_concat(i);
            benchmark::DoNotOptimize(res);
        }
}
BENCHMARK(FB_nonConcat);

static void FB_composable(benchmark::State& state){
    for (auto _ : state)
        for (auto i = 1; i < 101; i++){
            auto res = fizzbuzz_composable(i);
            benchmark::DoNotOptimize(res);
        }
}
BENCHMARK(FB_composable);

BENCHMARK_MAIN();