#include <iostream>

// Рекурсивная функция для проверки, можно ли достичь 1 из N
std::string canReachOne(int n) {
    // Базовый случай: если мы уже на 1, то ответ "YES"
    if (n == 1) {
        return "YES";
    }

    // Если n меньше 1, то ответ "NO"
    else if (n < 1) {
        return "NO";
    }

    // Если n делится на 3, рекурсивно вызываем функцию для n-3
    else if (n % 3 == 0) {
        return canReachOne(n - 3);
    }

    // Если n делится на 5, рекурсивно вызываем функцию для n-5
    else if (n % 5 == 0) {
        return canReachOne(n - 5);
    }

    // В противном случае ответ "NO"
    else {
        return "NO";
    }
}

int main() {
    // Ввод числа N
    int N;
    std::cin >> N;

    // Вывод результата
    std::cout << canReachOne(N) << std::endl;

    return 0;
}