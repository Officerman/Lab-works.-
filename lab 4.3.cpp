#include <iostream>

// Функция для вычисления N-го числа Фибоначчи
int fibonacci(int n) {
    // Базовый случай: если n равно 0, возвращаем 0
    if (n == 0) {
        return 0;
    }
    // Базовый случай: если n равно 1, возвращаем 1
    else if (n == 1) {
        return 1;
    }
    // Рекурсивно вызываем функцию для n-1 и n-2 и возвращаем их сумму
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    // Ввод числа N
    int N;
    std::cin >> N;

    // Вызов функции для вычисления N-го числа Фибоначчи и вывод результата
    std::cout << fibonacci(N) << std::endl;

    return 0;
}
