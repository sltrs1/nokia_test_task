//
// Created by sergey on 18/1/20.
//

#include "list_fifth.h"


void list_fifth() {

    size_t n;
    std::cout << "Enter list lenght: ";
    std::cin >> n;
    std::cout << std::endl;

    MyList * lst = generate_list(n);

    std::cout << "Your list is: " << std::endl;
    print_list(lst);
    remove_every_fifth(lst);
    std::cout << "Your list after removal of every 5th element is: " << std::endl;
    print_list(lst);

}

MyList * generate_list(size_t len) {

    // Если требуется создать спиок длинны 0, то возвращается нулевой указатель
    if (len == 0) {
        return nullptr;
    }

    MyList * head = new MyList;

    MyList * current_node = head;

    for (size_t i = 0; i < len; i++) {

        current_node->payload = i+1;
        current_node->next = nullptr;
        // Для последнего элемента следующий не создается
        if (i != len - 1) {
            current_node->next = new MyList;
            current_node = current_node->next;
        }
    }

    return head;
}

void remove_every_fifth(MyList * head) {

    MyList * node = head;
    size_t count = 1;
    while (node) {

        // Находится 4-й элемент и удаляется следующий за ним
        if (count % 4 == 0) {

            if (node->next) {
                MyList * tmp = node->next;
                node->next = node->next->next;
                delete tmp;
            }

        }
        count++;

        if (node) {
            node = node->next;
        }

    }

}


void print_list(MyList * head) {

    // Рекурсивно выводить значения элементов списка, пока он не кончится
    if (head != nullptr) {
        std::cout << head->payload << " ";
        print_list(head->next);
    }

    // Если список кончился, перевести строку
    if (head == nullptr) {
        std::cout << std::endl;
    }

}