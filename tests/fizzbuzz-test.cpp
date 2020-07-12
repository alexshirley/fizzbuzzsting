#include <include/gtest/gtest.h>
#include <fizzbuzz_basic_non_concat.h>
#include <fizzbuzz_composable.h>

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

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}