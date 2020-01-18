//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
#define NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H

#include <iostream>
#include <functional>

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

size_t TreeHeight(TreeNodeMod * node);

void tree_longest_paths();


#endif //NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
