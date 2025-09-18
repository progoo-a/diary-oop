#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>

int main() {
    constexpr int N = 10;
    std::vector<int> data;
    data.reserve(N);

    for (auto i : std::views::iota(0, N)) {
        int value;
        std::cin >> value;
        data.push_back(value);
    }

    auto sum = std::reduce(data.begin(), data.end(), 0);
    auto average = static_cast<double>(sum) / N;

    std::cout << "Moyenne : " << average << '\n';
}
