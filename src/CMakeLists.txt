cmake_minimum_required(VERSION 3.10.0)

add_executable(proj_test test.cpp lib.cpp)
# ^ Взять test.cpp , собрать вместе, назвать proj_test (proj_test.exe)
target_link_libraries(proj_test PUBLIC doctest::doctest default)
# ^ Использовать в proj_test библиотеки doctest::doctest и default
doctest_discover_tests(proj_test)
# ^ Прочитать из proj_test список тестов

#include(lib.cpp)

add_executable(proj lib.cpp main.cpp)

target_link_libraries(proj PUBLIC default CONAN_PKG::fmt nana::nana CONAN_PKG::libjpeg CONAN_PKG::libpng)
target_link_libraries(proj_test PUBLIC default CONAN_PKG::fmt nana::nana CONAN_PKG::libjpeg CONAN_PKG::libpng)