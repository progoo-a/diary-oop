#include <limits>
#include <vector>
#include <cmath>

std::vector<int> data;
int min() {
    auto value = std::numeric_limits<int>::max();
    for (auto v : data) {
        value = std::min(v, value);
    }
}

int main() {
}