//
// Created by sergey on 18/1/20.
//


#include "words_in_text.h"
#include "words_in_text_ref.h"

void words_in_text() {

    size_t menu = 0;
    std::string text;

    // Простенькое меню для ввода текста. Если лень вводить текст, можно взять готовый.
    while (menu < 1 || menu > 2) {

        std::cout << "Type 1 if you want to enter text manually" << std::endl;
        std::cout << "Type 2 if you want to use default text" << std::endl;
        std::string s;
        std::getline(std::cin, s);
        menu = s[0]- '0';
    }

    if (menu == 1) {
        std::cout << "Enter your text (empty line to stop): " << std::endl;

        std::string s;
        do {
            std::getline(std::cin, s);
            if (!s.empty()) {
                text += s + "\n";
            }
        } while (!s.empty());
    }

    if (menu == 2) {
        text = text_ref;
    }

    std::cout << "Your text is: " << std::endl;
    std::cout << text << std::endl;
    std::cout << std::endl;

    auto result = count_words(text);

    print_words(result);


}

std::map<size_t, size_t> count_words(std::string & text){

    // Создаем локальную копию текста, чтобы не испортить оригинал
    // Здесь это излишне, но привычку так просто не изжить
    std::string clean_text(text);

    // Удаляем все знаки препинания
    for (size_t i = 0; i < strlen(punctuation_marks); i++) {
        clean_text.erase(std::remove(clean_text.begin(), clean_text.end(), punctuation_marks[i]), clean_text.end());
    }

    std::map<size_t, size_t> result;

    std::istringstream iss(clean_text);

    // Итерируем текст по словам
    while (iss) {
        std::string s;
        iss >> s;
        // Пропуск символа конца строки
        if (s.empty()) {
            continue;
        }
        size_t len = s.size();

        // Добавляем найденную длинну в словарь
        // Если такая длинна уже встречалась ранее, добавления не будет, поэтому увеличиваем счетчик руками
        auto ins_op_res = result.insert({len, 1});
        if (!ins_op_res.second) {
            result[len] += 1;
        }
    }

    return result;
}

void print_words(std::map<size_t, size_t> & words) {

    // Если был введен пустой текст, то словарь следующий цикл ничего не выведет
    // и будет непонятно, это ошибка или корректный результат
    // Поэтому обрабатываем этот случай отдельно
    if (words.empty() ) {
        std::cout << "Text is empty" << std::endl;
        return;
    }

    for (const auto & [a, b] : words ) {
        std::cout << "Len = " << a << ", num of words = " << b << std::endl;
    }

}