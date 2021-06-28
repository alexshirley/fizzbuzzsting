cmake_minimum_required(VERSION 3.13)
project(fizzbuzz LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)

# At first, we want all the targets defined in the subdirectories to have the same warnings configured.
if (MSVC)
    add_compile_options(/W4 /WX)
    add_compile_options(/wd4127) # conditional expression is constant
    add_compile_options(/wd4244) # 'argument' : conversion from 'type1' to 'type2', possible loss of data
    add_compile_options(/wd4996) # Your code uses a function, class member, variable, or typedef that's marked deprecated
    add_compile_options(/wd4201) # nonstandard extension used : nameless struct/union
    add_compile_options(/wd4267) # conversion from 'size_t' to 'int', possible loss of data
    add_compile_options(/wd4204) # nonstandard extension used: non-constant aggregate initializer
    add_compile_options("/MT$<$<CONFIG:Release>:>")
else()
    add_compile_options(-g -Wall -Wextra -Wno-error=incompatible-pointer-types)
    add_compile_options(-Wno-error=incompatible-pointer-types)
    add_compile_options(-Wno-error=unused-parameter)
    add_compile_options(-Wno-error=unused-function)
    add_compile_options(-Wno-error=implicit-function-declaration)
    add_compile_options(-Wno-error=pedantic)
endif()

if (WIN32)
    # We target Windows 7
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(../third_party/google/benchmark build/benchmark)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

include_directories(
    .
    ../inc
)

add_executable(${PROJECT_NAME}
    ../src/fizzbuzz_basic_non_concat.cpp
    ../src/fizzbuzz_composable.cpp
    ../src/fizzbuzz_lambda_opt_concat.cpp
    ../src/fizzbuzz_lambda_concat.cpp
    fizzbuzz-test.cpp
)

# googletest
target_link_libraries("${PROJECT_NAME}" gtest_main)

add_executable(${PROJECT_NAME}-bench
    ../src/fizzbuzz_basic_non_concat.cpp
    ../src/fizzbuzz_composable.cpp
    ../src/fizzbuzz_lambda_opt_concat.cpp
    ../src/fizzbuzz_lambda_concat.cpp
    fizzbuzz-bench.cpp
)

# google benchmark
target_link_libraries("${PROJECT_NAME}-bench" benchmark::benchmark)


add_test(${PROJECT_NAME}-test ${PROJECT_NAME})