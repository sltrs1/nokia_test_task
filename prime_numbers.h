//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_PRIME_NUMBERS_H
#define NOKIA_TEST_TASK_PRIME_NUMBERS_H

#include <vector>
#include <cmath>
#include <iostream>



void prime_numbers();

void find_n_primes(size_t n, std::vector<size_t>& primes);

void print_vector_primes(std::vector<size_t>& primes);

bool check_result(std::vector<size_t>& primes);

#endif //NOKIA_TEST_TASK_PRIME_NUMBERS_H
