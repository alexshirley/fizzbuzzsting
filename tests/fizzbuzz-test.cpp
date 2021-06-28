#include <include/gtest/gtest.h>
#include <fizzbuzz_basic_non_concat.h>
#include <fizzbuzz_composable.h>
#include <fizzbuzz_lambda_opt_concat.h>
#include <fizzbuzz_lambda_concat.h>
#include <fizzbuzz_lut.h>

namespace fizzbuzz{

class fizzbuzz_sanity_test :public ::testing::Test{

};

TEST_F(fizzbuzz_sanity_test, fb_non_concat){
    auto should_be_fizz = fizzbuzz_basic_non_concat(3);
    EXPECT_STREQ(should_be_fizz.c_str(),"Fizz");
    auto should_be_buzz = fizzbuzz_basic_non_concat(5);
    EXPECT_STREQ(should_be_buzz.c_str(),"Buzz");
    auto should_be_fizzbuzz = fizzbuzz_basic_non_concat(15);
    EXPECT_STREQ(should_be_fizzbuzz.c_str(),"FizzBuzz");
}

TEST_F(fizzbuzz_sanity_test, fb_composable){
    auto should_be_fizz = fizzbuzz_composable(3);
    EXPECT_STREQ(should_be_fizz.c_str(),"Fizz");
    auto should_be_buzz = fizzbuzz_composable(5);
    EXPECT_STREQ(should_be_buzz.c_str(),"Buzz");
    auto should_be_fizzbuzz = fizzbuzz_composable(15);
    EXPECT_STREQ(should_be_fizzbuzz.c_str(),"FizzBuzz");
}

TEST_F(fizzbuzz_sanity_test, fb_lambda_opt){
    auto should_be_fizz = fizzbuzz_lambda_opt_concat(3);
    EXPECT_STREQ(should_be_fizz.c_str(),"Fizz");
    auto should_be_buzz = fizzbuzz_lambda_opt_concat(5);
    EXPECT_STREQ(should_be_buzz.c_str(),"Buzz");
    auto should_be_fizzbuzz = fizzbuzz_lambda_opt_concat(15);
    EXPECT_STREQ(should_be_fizzbuzz.c_str(),"FizzBuzz");
}

TEST_F(fizzbuzz_sanity_test, fb_lambda){
    auto should_be_fizz = fizzbuzz_lambda_concat(3);
    EXPECT_STREQ(should_be_fizz.c_str(),"Fizz");
    auto should_be_buzz = fizzbuzz_lambda_concat(5);
    EXPECT_STREQ(should_be_buzz.c_str(),"Buzz");
    auto should_be_fizzbuzz = fizzbuzz_lambda_concat(15);
    EXPECT_STREQ(should_be_fizzbuzz.c_str(),"FizzBuzz");
}

TEST_F(fizzbuzz_sanity_test, fb_lut){
    auto should_be_fizz = fizz_buzz_lut(3);
    EXPECT_STREQ(std::string(std::get<0>(should_be_fizz)).c_str(),"Fizz");
    auto should_be_buzz = fizz_buzz_lut(5);
    EXPECT_STREQ(std::string(std::get<0>(should_be_buzz)).c_str(),"Buzz");
    auto should_be_fizzbuzz = fizz_buzz_lut(15);
    EXPECT_STREQ(std::string(std::get<0>(should_be_fizzbuzz)).c_str(),"FizzBuzz");
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}