#include <iostream>

// Функция для нахождения НОД с использованием алгоритма Евклида
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Ввод двух чисел
    int num1, num2;
    std::cin >> num1 >> num2;

    // Вызов функции для нахождения НОД и вывод результата
    std::cout << gcd(num1, num2) << std::endl;

    return 0;
}