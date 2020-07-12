#include <fizzbuzz_basic_non_concat.h>
#include <string>

std::string fizzbuzz_basic_non_concat(int n){
    if (n % 15 == 0){
        return "FizzBuzz";
    } else if (n % 3 == 0){
        return "Fizz";
    } else if (n % 5 == 0){
        return "Buzz";
    }
    return std::to_string(n);
}