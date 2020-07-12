#include <benchmark/benchmark.h>
#include <fizzbuzz_basic_non_concat.h>

static void FB_nonConcat(benchmark::State& state){
    for (auto _ : state)
        for (auto i = 1; i < 101; i++){
            auto res = fizzbuzz_basic_non_concat(i);
            benchmark::DoNotOptimize(res);
        }
}
BENCHMARK(FB_nonConcat);

BENCHMARK_MAIN();