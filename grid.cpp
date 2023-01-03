#include <iostream>
#include <iterator>
using namespace std;

#define DIM 9

class Grid {
   private:
    int grid[DIM][DIM];

    void initGrid() {
        for (int i = 0; i < sizeof grid / sizeof grid[0]; i++) {
            for (int j = 0; j < sizeof grid[0] / sizeof(int); j++) {
                grid[i][j] = 0;
            }
        }
    }

   public:
    Grid() {}

    void returnGrid(int res[DIM][DIM]) {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                res[i][j] = grid[i][j];
            }
        }
    }
};

int main() {
    Grid grid;
    int board[DIM][DIM];

    grid.returnGrid(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}