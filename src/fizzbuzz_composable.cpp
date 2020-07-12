#include <functional>
#include <fizzbuzz_composable.h>

// This version of fizzbuzz taken and modified from Kevlin Henney - Lean Code 2019 Devternity Talk
// https://www.youtube.com/watch?v=-nWhH-4wWBU

using namespace std;

std::string fizzbuzz_composable(int n){
    auto test = 
    [=](auto d, auto s, std::function<string(string)> f){
        return n % d == 0 ? 
        [=](string){return s + f("");} : f;
    };
    auto fizz = [=](auto&& args){return test(3,"Fizz",std::forward<decltype(args)>(args));};
    auto buzz = [=](auto&& args){return test(5,"Buzz",std::forward<decltype(args)>(args));};
    auto id = [](auto s){return s;};
    return fizz(buzz(id))(to_string(n));
}