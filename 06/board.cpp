#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
using namespace std;

class Board;

class Cell {
    int x, y;
    bool is_bomb;
    public:
    Cell(int x, int y, bool is_bomb = false): x{x}, y{y}, is_bomb{is_bomb} {}

    string str() {
        return is_bomb ? "B" : ".";
    }

    void display(ostream &os) {
        os << str();
    }

    void iterate_neighbours(function<void(Cell&)>cb) {
        // ...
    }

    friend Board;
};

class Board {
    vector< vector<Cell> > cells;
    int width, height;

    void swap (Cell &a, Cell &b)
    {
        bool temp = a.is_bomb;
        a.is_bomb = b.is_bomb;
        b.is_bomb = temp;
    }

    public:

    Board(int height=7, int width=7, int bombs=5) : width{width}, height{height} {
        srand (time(NULL));
        for (int w = 0; w < width; w++) {
            cells.push_back(vector<Cell>());
            for (int h = 0; h < height; h++)
                cells.back().push_back(Cell(w, h, bombs-- > 0));
        }
    }

    void display(ostream &os) {
        for (auto &row : cells) {
            for (auto &cell : row)
                os << cell.str();
            os << endl;
        }
    }

    void randomize () {
        // Fishers-yates
        int n = width * height;
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(cells[i / width][i % width], cells[j / width][j % width]);
        }
    }
};

int main() {
    Board board;
    board.display(cout);
    board.randomize();
    cout << "-----------" << endl;
    board.display(cout);
}
