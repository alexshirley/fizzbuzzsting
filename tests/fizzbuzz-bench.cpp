#include <benchmark/benchmark.h>
#include <fizzbuzz_basic_non_concat.h>
#include <fizzbuzz_composable.h>
#include <fizzbuzz_lambda_opt_concat.h>
#include <fizzbuzz_lambda_concat.h>

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

static void FB_lambda_opt_concat(benchmark::State& state){
    for (auto _ : state)
        for (auto i = 1; i < 101; i++){
            auto res = fizzbuzz_lambda_opt_concat(i);
            benchmark::DoNotOptimize(res);
        }
}
BENCHMARK(FB_lambda_opt_concat);

static void FB_lambda_concat(benchmark::State& state){
    for (auto _ : state)
        for (auto i = 1; i < 101; i++){
            auto res = fizzbuzz_lambda_concat(i);
            benchmark::DoNotOptimize(res);
        }
}
BENCHMARK(FB_lambda_concat);

BENCHMARK_MAIN();