cmake_minimum_required(VERSION 3.15)
project(nokia_test_task)

set(CMAKE_CXX_STANDARD 17)

add_executable(nokia_test_task main.cpp prime_numbers.h prime_numbers.cpp prime_numbers_1000.h words_in_text.cpp words_in_text.h words_in_text_ref.h list_fifth.cpp list_fifth.h bit_operations.cpp bit_operations.h)