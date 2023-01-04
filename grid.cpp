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

        // fill diagonal
        for (int i = 0; i < (int)sqrt(DIM); i++) {
            int arr[DIM];
            iota(arr, arr + DIM, 1);
            shuffle(arr, arr + DIM, generator);
            // cout << "shuffled";
            // for (int i = 0; i < DIM; i++) {
            //     cout << arr[i] << " ";
            // }
            // cout << "\n";
            int idx = 0;
            for (int row = i * 3; row < i * 3 + 3; row++) {
                for (int col = i * 3; col < i * 3 + 3; col++) {
                    grid[row][col] = arr[idx];
                    idx += 1;
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
            if (row.count(grid[idx][i])) {
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
                if (sqr.count(grid[i][j])) {
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
            if (col.count(grid[i][idx])) {
                return false;
            }
            col.insert(grid[i][idx]);
        }
        return true;
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
    cout << "\n";
    cout << "Row 1: " << grid.checkRow(1) << "\n";
    cout << "Row 9: " << grid.checkRow(9) << "\n";
    cout << "Col 1: " << grid.checkCol(1) << "\n";
    cout << "Col 9: " << grid.checkCol(9) << "\n";
    cout << "Sqr 1: " << grid.checkSqr(1) << "\n";
    cout << "Sqr 2: " << grid.checkSqr(2) << "\n";
    cout << "Sqr 5: " << grid.checkSqr(5) << "\n";
    cout << "Sqr 8: " << grid.checkSqr(8) << "\n";
    cout << "Sqr 9: " << grid.checkSqr(9) << "\n";
    return 0;
}