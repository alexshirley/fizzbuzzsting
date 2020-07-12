#include <include/gtest/gtest.h>
#include <fizzbuzz_basic_non_concat.h>

namespace fizzbuzz{

class fizzbuzz_sanity_test :public ::testing::Test{

};

TEST_F(fizzbuzz_sanity_test, fizzbuzz_non_concat){
    auto should_be_fizz = fizzbuzz_basic_non_concat(3);
    ASSERT_STREQ(should_be_fizz.c_str(),"Fizz");
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}