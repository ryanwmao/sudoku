#include <iostream>
#include <random>
#include <set>
using namespace std;

#define DIM 9

default_random_engine generator;
uniform_int_distribution<int> uniform(1, 9);

/* 3x3 grid indices:
 ____ ____ ____
| 1  | 2  | 3  |
|____|____|____|
| 4  | 5  | 6  |
|____|____|____|
| 7  | 8  | 9  |
|____|____|____|
*/
class Grid {
   private:
    int grid[DIM][DIM];

    void initGrid() {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                grid[i][j] = 0;
            }
        }

        int randoms[DIM * DIM][DIM];
        int idxs[DIM * DIM];
        for (int i = 0; i < DIM * DIM; i++) {
            iota(randoms[i], randoms[i] + DIM, 1);
            shuffle(randoms[i], randoms[i] + DIM, generator);
            idxs[i] = 0;
        }

        int idx = 0;
        while (idx < DIM * DIM) {
            int row = idx / DIM + 1;
            int col = idx % DIM + 1;

            if (valid(row, col, randoms[idx][idxs[idx]])) {
                grid[row - 1][col - 1] = randoms[idx][idxs[idx]];
                idx += 1;
            } else {
                idxs[idx] += 1;
                while (idxs[idx] > 9) {
                    idxs[idx] = 0;
                    idx -= 1;
                    idxs[idx] += 1;
                }
            }
        }
    };

   public:
    Grid() {
        cout << "init board \n";
        initGrid();
    }

    bool checkRow(int idx) {
        if (idx < 1 || idx > DIM) {
            return false;
        }
        idx -= 1;
        set<int> row;
        for (int i = 0; i < DIM; i++) {
            if (grid[idx][i] != 0 && row.count(grid[idx][i])) {
                return false;
            }
            row.insert(grid[idx][i]);
        }

        return true;
    }

    bool checkSqr(int idx) {
        int col = (idx * 3 - 3) % DIM;
        int row = (idx - 1) / (int)sqrt(DIM) * 3;
        set<int> sqr;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] != 0 && sqr.count(grid[i][j])) {
                    return false;
                }
                sqr.insert(grid[i][j]);
            }
        }
        return true;
    }

    bool checkCol(int idx) {
        if (idx < 1 || idx > DIM) {
            return false;
        }
        idx -= 1;
        set<int> col;
        for (int i = 0; i < DIM; i++) {
            if (grid[i][idx] != 0 && col.count(grid[i][idx])) {
                return false;
            }
            col.insert(grid[i][idx]);
        }
        return true;
    }

    bool valid(int row, int col, int num) {
        if (row < 1 or row > DIM or col < 1 or col > DIM or num < 1 or
            num > DIM) {
            return false;
        }

        int prev = grid[row - 1][col - 1];
        grid[row - 1][col - 1] = num;
        bool validNum = checkCol(col) && checkRow(row) &&
                        checkSqr(((row - 1) / 3) * 3 + 1 + (col - 1) / 3);
        grid[row - 1][col - 1] = prev;
        return validNum;
    }

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