#include <string>
#include <iostream> 

#include <utility>
#include <string>
#include <cstddef>

std::string repeat(std::string str, const std::size_t n)
{
    if (n == 0) {
        str.clear();
        str.shrink_to_fit();
        return str;
    } else if (n == 1 || str.empty()) {
        return str;
    }
    const auto period = str.size();
    if (period == 1) {
        str.append(n - 1, str.front());
        return str;
    }
    str.reserve(period * n);
    std::size_t m {2};
    for (; m < n; m *= 2) str += str;
    str.append(str.c_str(), (n - (m / 2)) * period);
    return str;
}

std::string operator*(std::string str, std::size_t n)
{
    return repeat(std::move(str), n);
}

int main() {
    std::string u = "abc";
    std::cout << u * 10;
}