#include <functional>
#include <vector>
#include <iostream>

class Class
{
public:
    std::vector<int> data;
    int reduce(std::function<int(int, int)> cb, int value = 0)
    {
        for (auto &el : this->data)
            value = cb(value, el);
        return value;
    }
};

int main()
{
    Class collection;
    collection.data.push_back(4);
    collection.data.push_back(8);
    collection.data.push_back(15);
    collection.data.push_back(16);
    collection.data.push_back(23);
    collection.data.push_back(42);

    int ret = collection.reduce([](int value, int element) {
        std::cout << element << " ";
        return value + (element % 2 ? 0 : element);
    });

    std::cout << std::endl
              << ret;
}
