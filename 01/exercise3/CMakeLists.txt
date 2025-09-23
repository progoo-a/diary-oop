cmake_minimum_required(VERSION 3.14)
project(StatisticsTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Récupération automatique de gtest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(statistics_test statistics_test.cpp)
target_link_libraries(statistics_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(statistics_test)
