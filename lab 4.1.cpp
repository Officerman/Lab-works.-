#include <iostream>

// Функция для перемещения диска с одного стержня на другой
void moveDisk(int disk, int source, int target) {
    std::cout << disk << " " << source << " " << target << std::endl;
}

// Рекурсивная функция для перемещения башни из n дисков со стержня source на стержень target, используя вспомогательный стержень auxiliary
void hanoi(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        moveDisk(1, source, target);
    } else {
        hanoi(n - 1, source, auxiliary, target);
        moveDisk(n, source, target);
        hanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    // Ввод числа дисков
    int n;
    std::cin >> n;

    // Вызов функции Ханойских башен
    hanoi(n, 1, 3, 2);

    return 0;
}
