#include <iostream>

// Функция для перемещения диска с одного стержня на другой
void moveDisk(int disk, int source, int target) {
    std::cout << disk << " " << source << " " << target << std::endl;
}

// Рекурсивная функция для перемещения башни из n дисков со стержня source на стержень target, используя вспомогательный стержень auxiliary
void hanoiWithRestrictions(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        moveDisk(1, source, auxiliary);
        moveDisk(1, auxiliary, target);
    } else {
        hanoiWithRestrictions(n - 1, source, target, auxiliary);
        moveDisk(n, source, auxiliary);
        hanoiWithRestrictions(n - 1, target, source, auxiliary);
        moveDisk(n, auxiliary, target);
        hanoiWithRestrictions(n - 1, source, target, auxiliary);
    }
}

int main() {
    // Ввод числа дисков
    int n;
    std::cin >> n;

    // Вызов функции Ханойских башен с ограничениями
    hanoiWithRestrictions(n, 1, 3, 2);

    return 0;
}