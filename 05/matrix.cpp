#include <vector>
#include <iostream>

class Board{
    public:
    std::vector< std::vector<Cell> > board;

    Board() {}
    void init() {
            int k = 0;
    for(int x = 0; x < 5; x++) {
        std::vector<Cell> row;
        for (int y = 0; y < 5; y++) {
            row.push_back(Cell(x,y, (k++)%2));
        }
        board.push_back(row);
    }
    }
    void display() {
            for(int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            std::cout << board[x][y].isBomb << ' ';
        }
        std::cout << std::endl;
    }
    }
};

class Cell {
    public:
    int x, y;
    bool isBomb;
    Cell(int x, int y, bool isBomb) : x{x}, y{y}, isBomb{isBomb} {}
};

int main() {
    Board board;

    board.init(5);
    board.display();
    board.reveal(3,4);
    board.diplsay();
    assert(board.getStatus(2,3) == Board::BOMB);
}
