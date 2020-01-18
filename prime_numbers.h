//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_PRIME_NUMBERS_H
#define NOKIA_TEST_TASK_PRIME_NUMBERS_H

#include <vector>
#include <cmath>
#include <iostream>


// Функция, в которой выполняется задание по поиску простых чисел
void prime_numbers();

// Функция, в которой находятся первые n прочтых чисел и помещаются в динамический массив primes
void find_n_primes(size_t n, std::vector<size_t>& primes);

// Печать вектора простых чисел
void print_vector_primes(std::vector<size_t>& primes);

// Проверка правильости нахождения простых чисел путем равнения с эталоном
bool check_result(std::vector<size_t>& primes);

#endif //NOKIA_TEST_TASK_PRIME_NUMBERS_H
