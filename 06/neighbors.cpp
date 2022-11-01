/**
 * Ce programme fait quelque chose.
 */
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

/**
 * @brief gjgfkdlkgljg
 *
 */
class Matrix
{
    vector<vector<int>> matrix;

public:
    void neighbors(int x, int y, function<void(int &)> callback)
    {
        callback(matrix[x - 1][y - 1]); // Top left
        callback(matrix[x][y - 1]);     // Top
        callback(matrix[x + 1][y - 1]); // Top right
        callback(matrix[x - 1][y]);     // Left
        callback(matrix[x + 1][y]);     // Right
        callback(matrix[x - 1][y + 1]); // Bottom left
        callback(matrix[x + 1][y + 1]); // Bottom right
        callback(matrix[x][y + 1]);     // Bottom
    }
};

void display(int &value) { std::cout << value << std::endl; }
void add(int &value) { value += 2; }

int main()
{
    Matrix matrix;
    matrix.neighbors(3, 3, display);
    matrix.neighbors(3, 3, add);
    matrix.neighbors(3, 3, [](int &v){ v*= 42;});
    int u = 42;
    matrix.neighbors(3, 3, [=](int &v){ v = u;});
    int sum = 0;
    matrix.neighbors(3, 3, [&](int &v){ sum += v;});


    matrix.foo
}
