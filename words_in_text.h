//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_WORDS_IN_TEXT_H
#define NOKIA_TEST_TASK_WORDS_IN_TEXT_H

#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

// Функция, в которой выполняется задание по подсчету слов каждой длинны в тексте
void words_in_text();

// Функция непосредственного подствета слов
std::map<size_t, size_t> count_words(std::string & text);

// Печать результата
void print_words(std::map<size_t, size_t> & words);


#endif //NOKIA_TEST_TASK_WORDS_IN_TEXT_H
