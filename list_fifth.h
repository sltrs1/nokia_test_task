//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_LIST_FIFTH_H
#define NOKIA_TEST_TASK_LIST_FIFTH_H

#include <cstdio>
#include <iostream>

// Структура списка из задания
struct MyList {
    struct MyList * next;
    size_t payload;
};

// // Функция, в которой выполняется задание по удалению каждого пятого элемента списка
void list_fifth();

// Функция генерации списка
// Для наглядности список заполянется идущими подряд числами от 1 до длины списка
MyList * generate_list(size_t len);

// Непосредственное удаление каждого пятого элемента списка
void remove_every_fifth(MyList * head);

// Печать списка
void print_list(MyList * head);


#endif //NOKIA_TEST_TASK_LIST_FIFTH_H
