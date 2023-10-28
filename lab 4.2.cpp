#include <iostream>
#include <vector>
#include <climits>

// Функция для нахождения комбинаций монеток
void findCombinations(int N, const std::vector<int>& coins, std::vector<int>& current, std::vector<int>& result, int& minCoins) {
    if (N == 0) {
        // Проверяем, является ли текущая комбинация минимальной
        if (current.size() < minCoins) {
            minCoins = current.size();
            result = current;
        }
        return;
    }

    for (int coin : coins) {
        if (coin <= N) {
            current.push_back(coin);
            findCombinations(N - coin, coins, current, result, minCoins);
            current.pop_back();
        }
    }
}

int main() {
    // Ввод данных
    int N, M;
    std::cin >> N >> M;

    // Ввод достоинств монет
    std::vector<int> coins(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> coins[i];
    }

    // Поиск комбинации
    std::vector<int> current, result;
    int minCoins = INT_MAX;
    findCombinations(N, coins, current, result, minCoins);

    // Вывод результата
    if (result.empty()) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << result.size() << std::endl;
        for (int coin : result) {
            std::cout << coin << " ";
        }
    }

    return 0;
}