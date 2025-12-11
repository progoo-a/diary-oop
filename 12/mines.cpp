#include <vector>
#include <memory> 

struct Cell {
    bool is_mine;
    bool is_revealed;
    int neighboring_mines;
};

/**
 * Grille d'un démineur composé de cellules
 */
struct Grid {
    int width;
    int height;
    std::vector<std::vector<std::unique_ptr<Cell>>> cells;

    Grid(int w, int h) : width(w), height(h), cells(w, std::vector<std::unique_ptr<Cell>>(h)) {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                cells[x][y] = std::make_unique<Cell>();
            }
        }
    }

    void for_neighbors(int x, int y, auto func) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    func(*cells[nx][ny];);
                }
            }
        }
    }
};

int main() {
    Grid grid(10, 10);

    grid.for_neighbors(5, 5, [](Cell &neighbor) {
        neighbor.is_revealed = true;
    });

    int mines = 0;
    grid.for_neighbors(5, 5, [&mines](Cell &neighbor) {
        mines += (int)neighbor.is_mine;
    });
}