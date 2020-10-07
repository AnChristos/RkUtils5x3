cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(mult5x3-SIMD VERSION 1.0)

# C++ setting
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -pedantic -Werror  -O2 -g)

list(APPEND CMAKE_PREFIX_PATH $ENV{HOME}/.local/)
find_package(benchmark REQUIRED)
find_package (Threads)
find_package(Eigen3)

add_executable(mult5x3_test 
	       mult5x3.cxx
	       mult5x3_test.cxx)

add_executable(mult5x3_bench
               mult5x3.cxx	
      	       mult5x3_bench.cxx)

target_link_libraries(mult5x3_test  Eigen3::Eigen )
target_link_libraries(mult5x3_bench  benchmark::benchmark Eigen3::Eigen)

