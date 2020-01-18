//
// Created by sergey on 18/1/20.
//

#ifndef NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
#define NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H

// Структура дерева из задания
struct TreeNode {
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

// Модифицированная структура дерева из задания
// Я позволил себе такую вольность, потому что оперировать деревом без значений весьма затруднительно
struct TreeNodeMod {
    int data;
    struct TreeNodeMod* leftChild;
    struct TreeNodeMod* rightChild;
};

void tree_longest_paths();


#endif //NOKIA_TEST_TASK_TREE_LONGEST_PATHS_H
