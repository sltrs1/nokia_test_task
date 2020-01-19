//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
#define NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H

#include <iostream>
#include <functional>
#include <vector>

// Структура дерева из задания
struct TreeNode {
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

// Модифицированная структура дерева из задания
// Я позволил себе такую вольность, полагая, что суть задания не в этом,
// а так же потому, что оперировать деревом без значений весьма затруднительно
struct TreeNodeMod {
    int data;
    struct TreeNodeMod* leftChild;
    struct TreeNodeMod* rightChild;
};

// Реализацию дерева я взял из другого своего тестового задания, чтобы не тратить время
TreeNodeMod * MakeNode(int x);
TreeNodeMod * CreateBalancedTree(int arr[], int start, int end);
void PrintTreeTraversal(TreeNodeMod * n);
void PrintTreeByLevel(TreeNodeMod * n);

// // Функция, в которой выполняется задание по поиску максимально длинных путей в дереве
void tree_longest_paths();

// Измерение высоты дерева
size_t TreeHeight(TreeNodeMod * node);

// Функция поиска путей
std::vector<std::vector<int>> FindPaths(TreeNodeMod * node);

// Вспомогательная функция поиска путей
void FindPathHelper(TreeNodeMod * node, std::vector<std::vector<int>> & paths, std::vector<int> cur_path, size_t path_len_max);

// Печать найденных путей
void PrintPaths(std::vector<std::vector<int>>  & paths);


#endif //NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
