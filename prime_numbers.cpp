//
// Created by sergey on 18/1/20.
//

#include "prime_numbers.h"
#include "prime_numbers_1000.h"

void prime_numbers() {

    size_t n;
    // Для проверки захардкожены первые 1000 простых чисел
    std::cout << "How much prime numbers to find (no more than " <<  MAX_PR_NUMS << ")? : ";
    std::cin >> n;
    std::cout << std::endl;
    if (n > MAX_PR_NUMS) {
        n = MAX_PR_NUMS;
    }

    std::vector<size_t> primes;
    primes.reserve(n);

    find_n_primes(n, primes);

    bool check = check_result(primes);

    if (check) {
        print_vector_primes(primes);
    }


}

void find_n_primes(size_t n, std::vector<size_t>& primes) {

    // Если надо найти 0 чисел, то выходим.
    if (n == 0) {
        return;
    }

    primes.push_back(2); // Первое простое число
    size_t count = 1; // Количество найденных простых чисел

    // Проверяем все нечетные числа, начиная с 3. Единственное четное простое число это 2 и оно уже найдено
    for (int num = 3; count < n; num += 2) {

        bool is_prime = true;

        // Сначала проверяем, являются ли делителями уже найденные простые числа
        for (const auto & p : primes) {
            if (num % p == 0) {
                is_prime = false;
                break;
            }
        }

        // Если ни одно из простых чисеел не является делителем, то проверяем оставшиеся возможные нечетные числа
        // от последнего простого числа до корня из проверяемого числа
        if (is_prime) {
            for (int i = primes.back(); i < sqrt(num); i +=2) {
                if (num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
        }

        // Если делители не найдены, то число является простым, заносим его в массив
        if (is_prime) {
            primes.push_back(num);
            count += 1;
        }

    }

}

void print_vector_primes(std::vector<size_t>& primes) {

    std::cout << "First " << primes.size() << " primes are: " << std::endl;
    int i = 1;
    for (auto & a: primes) {
        std::cout << i++ << " " << a << " " << std::endl;
    }
    std::cout << std::endl;

}

bool check_result(std::vector<size_t>& primes) {

    bool flag = true;

    for (size_t i = 0; i < primes.size(); i++) {

        if (primes[i] != _1000_primes[i]) {
            flag = false;
            std::cerr << "First error is in " << i+1 << " prime number: " << primes[i] << " instead of " << _1000_primes[i] << std::endl;
            break;
        }

    }

    if (flag) {
        std:: cout << "Check passed" << std::endl;
    }

    return flag;
}