//
// Created by sergey on 18/1/20.
//

#include "tree_longest_paths.h"

void tree_longest_paths() {

    int n;
    std::cout << "Enter number of nodes (no more that 100): ";
    std::cin >> n;
    std::cout << std::endl;

    if (n < 0 ) {
        n = abs(n);
    }

    if (n > 100 ){
        n = 100;
    }

    int * arr = new int[n];

    for (size_t i = 0; i < n; i++) {
        arr[i] = i;
    }

    TreeNodeMod * head = CreateBalancedTree(arr, 0, n-1);

    PrintTreeTraversal(head);
    std::cout << std::endl;
    PrintTreeByLevel(head);


}

size_t TreeHeight(TreeNodeMod * node) {

    if (node == nullptr) {
        return 0;
    }
    else
    {
        int lheight = TreeHeight(node->leftChild);
        int rheight = TreeHeight(node->rightChild);

        if (lheight > rheight)
            return(lheight + 1);
        else
            return(rheight + 1);
    }

}

TreeNodeMod * MakeNode(int x) {
    TreeNodeMod * n = new TreeNodeMod;
    n->data = x;
    n->leftChild = nullptr;
    n->rightChild = nullptr;
    return n;
}

TreeNodeMod * CreateBalancedTree(int arr[], int start, int end) {

    if (arr == nullptr) {
        return nullptr;
    }

    if (end < start) {
        return nullptr;
    }

    int mid = (start + end) / 2;

    TreeNodeMod *n = MakeNode(arr[mid]);

    n->leftChild = CreateBalancedTree(arr, start, mid - 1);
    n->rightChild = CreateBalancedTree(arr, mid + 1, end);

    return n;
}

void PrintTreeTraversal(TreeNodeMod * n) {

    if (n == nullptr) {
        return;
    }

    PrintTreeTraversal(n->leftChild);
    std::cout << n->data << " ";
    PrintTreeTraversal(n->rightChild);

}

void PrintTreeByLevel(TreeNodeMod * n) {

    int h = TreeHeight(n);

    auto prnt = [](auto&& self, TreeNodeMod * n, int lvl){
        if (n == nullptr) {
            return;
        }
        if (lvl == 1) {
            std::cout << n->data << " ";
        }
        else {
            if (lvl > 1) {
                self(self, n->leftChild, lvl-1);
                self(self, n->rightChild, lvl-1);
            }
        }
    };

    for (int i = 1; i < h+1; i++) {
        prnt(prnt, n, i);
        std::cout << std::endl;
    }

}