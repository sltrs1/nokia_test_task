#include <iostream>

#include "prime_numbers.h"
#include "words_in_text.h"
#include "list_fifth.h"
#include "bit_operations.h"
#include "tree_longest_paths.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    size_t menu = 0;

    while (menu != 6) {

        std::cout << "=========================" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1 - Prime Numbers" << std::endl;
        std::cout << "2 - Calculate words in text" << std::endl;
        std::cout << "3 - Remove every 5th element from the list" << std::endl;
        std::cout << "4 - Perform bit operations" << std::endl;
        std::cout << "5 - Find longest paths in the tree" << std::endl;
        std::cout << "6 - Exit" << std::endl;

        std::cin >> menu;

        switch(menu) {

            case 1 :
                prime_numbers();
                std::cout << "Press any key to continue" << std::endl;
                std::cin.ignore();
                break;

            case 2 :
                words_in_text();
                std::cout << "Press any key to continue" << std::endl;
                std::cin.ignore();
                break;

            case 3 :
                list_fifth();
                std::cout << "Press any key to continue" << std::endl;
                std::cin.ignore();
                break;

            case 4 :
                bit_operations();
                std::cout << "Press any key to continue" << std::endl;
                std::cin.ignore();
                break;

            case 5 :
                tree_longest_paths();
                std::cout << "Press any key to continue" << std::endl;
                std::cin.ignore();
                break;

            case 6 :
                break;

            default:
                break;

        };

    }

    return 0;
}
