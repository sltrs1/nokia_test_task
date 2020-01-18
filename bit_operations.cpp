//
// Created by sergey on 18/1/20.
//

#include "bit_operations.h"


void bit_operations() {

    uint32_t t;

    std::cout << "Enter uint32_t number: ";
    std::cin >> t;
    std::cout << std::endl;

    //t = UINT32_MAX;

    std::cout << "Your number is: " << t << std::endl;
    print_binary_form(t);

    std::cout << "----------------------- "<< std::endl;
    std::cout << "Solution via std::bitset :" << std::endl;
    auto res1 = bit_operations_bitset(t);
    std::cout << "Maximal possible value "<< std::endl;
    std::cout << res1.first << std::endl;
    print_binary_form(res1.first);
    std::cout << "Minimal possible value " << std::endl;
    std::cout << res1.second << std::endl;
    print_binary_form(res1.second);

    std::cout << "----------------------- " << std::endl;
    std::cout << "Solution via direct binary operations :" << std::endl;
    auto res2 = bit_operations_casual(t);
    std::cout << "Maximal possible value " << std::endl;
    std::cout << res2.first << std::endl;
    print_binary_form(res2.first);
    std::cout << "Minimal possible value " << std::endl;
    std::cout << res2.second << std::endl;
    print_binary_form(res2.second);
}

void print_binary_form(uint32_t t) {
    std::cout << std::bitset<32>(t) << std::endl;
}

std::pair<uint32_t, uint32_t> bit_operations_bitset(uint32_t t) {
    std::bitset<32> bs(t);
    size_t cnt = bs.count(); // Ыозвращает количесиво битов, установленных в 1
    std::bitset<32> bs_max(0);
    std::bitset<32> bs_min(0);

    // Для максимально возможного числа устанавливаются в 1 старшие разряды
    // Для минимально возможного - младшие
    for (size_t i = 0; i < cnt; i++) {
        bs_max.set(31-i, true);
        bs_min.set(i, true);
    }

    // Из битсетов создаются обычные числа
    return {(uint32_t)bs_max.to_ulong(), (uint32_t)bs_min.to_ulong()};
}

std::pair<uint32_t, uint32_t> bit_operations_casual(uint32_t t) {

    size_t cnt = 0;
    uint32_t max = 0;
    uint32_t min = 0;
    for (size_t i = 0; i < 32; i++) {
        // Вычленяется каждый разряд и его значение прибавляется к счетчику
        cnt += (t & (1u << i) ) >> i;
    }

    // Для максимально возможного числа устанавливаются в 1 старшие разряды
    // Для минимально возможного - младшие
    for (size_t i = 0; i < cnt; i++) {
        min |= 1u << i;
        max |= 1u << (31u - i);
    }

    return {max, min};

}