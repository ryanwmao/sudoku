#include <iostream>
#include <iterator>
using namespace std;

class Grid {
   private:
    int grid[9][9];

    void initGrid() {
        for (int i = 0; i < sizeof grid / sizeof grid[0]; i++) {
            for (int j = 0; j < sizeof grid[0] / sizeof(int); j++) {
                grid[i][j] = 0;
            }
        }
    }

   public:
    Grid() {}

    void returnGrid(int*** ptr) {
        int dim = sizeof grid / sizeof grid[0];
        int** temp = new int*[dim];
        for (int i = 0; i < sizeof grid / sizeof grid[0]; i++) {
            temp[i] = new int[dim];
            for (int j = 0; j < sizeof grid[0] / sizeof(int); j++) {
                temp[i][j] = grid[i][j];
            }
        };

        *ptr = temp;
    }
};

int main() {
    Grid grid;
    int** ptr;

    grid.returnGrid(&ptr);

    //  for (int i = 0; i < sizeof(&ptr) / sizeof(&ptr[0]); i++) {
    //      for (int j = 0; j < sizeof(&ptr[0]) / sizeof(int); j++) {
    //          cout << ptr[i][j] << " ";
    //      }
    //      cout << "\n";
    //  }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}