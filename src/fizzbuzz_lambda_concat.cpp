#include <fizzbuzz_lambda_concat.h>

using namespace std;

std::string fizzbuzz_lambda_concat(int n){
    auto test = [=](int divisor, const char * s) -> string{
        return (n%divisor ==0) ?  s : "";
    };
    string res = test(3,"Fizz") + test(5,"Buzz");
    return (!res.empty()) ? res : to_string(n);
}