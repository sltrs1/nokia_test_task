//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_BIT_OPERATIONS_H
#define NOKIA_TEST_TASK_BIT_OPERATIONS_H

#include <iostream>
#include <bitset>


// Функция, в которой выполняется задание по нахождению минимального и максимального
// числа, содержащего столько же единиц в двоичной форме, сколько и заданное число
void bit_operations();

// Печать двоичной формы числа
void print_binary_form(uint32_t t);

// Решение задачи с использованием std::bitmap
std::pair<uint32_t, uint32_t> bit_operations_bitset(uint32_t t);

// Решение задачи с использованием битовых операций
std::pair<uint32_t, uint32_t> bit_operations_casual(uint32_t t);

#endif //NOKIA_TEST_TASK_BIT_OPERATIONS_H
