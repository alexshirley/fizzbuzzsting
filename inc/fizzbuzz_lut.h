#include <variant>
#include <string_view>
#include <array>

using fizz_buzz_lut_type = std::variant<std::string_view,int>;

constexpr fizz_buzz_lut_type fizz_buzz_lut(int i){
    constexpr std::array<std::string_view,4> lut = {"","Fizz","Buzz","FizzBuzz"};
    unsigned isDiv3 = [](int i)->unsigned{return i%3 == 0;}(i);
    unsigned isDiv5 = [](int i)->unsigned{return i%5 == 0;}(i);
    unsigned idx = (isDiv3 | (isDiv5 << 1));
    if (idx == 0) return i;
    return {lut[idx]};
}