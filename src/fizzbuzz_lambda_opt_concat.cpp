#include <fizzbuzz_lambda_opt_concat.h>
#include <optional>

using namespace std;

std::string fizzbuzz_lambda_opt_concat(int n) {
    auto test = [=](int divisor, const char * s){
        return (n%divisor ==0) ?  optional<string>{s} : nullopt;
    };
    string res = test(3,"Fizz").value_or("") + test(5,"Buzz").value_or("");
    return (!res.empty()) ? res : to_string(n);
}