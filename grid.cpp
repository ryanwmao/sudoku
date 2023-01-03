#include <iostream>
using namespace std;

class Grid {
   private:
    int grid[9][9];

    void initGrid() {
        for (int i = 0; i < sizeof grid / sizeof grid[0]; i++) {
            for (int j = 0; j < sizeof grid[0] / sizeof(int); j++) {
            }
        }
    }

   public:
    Grid() {}

    void returnGrid(int** ptr) {
        for (int i = 0; i < (**grid).length(); i++) {
        }

        ptr = grid;
    }
};

int main() {
    Grid grid;
    int** ptr;
    grid.returnGrid(ptr);

    cout << ptr[0][0];
    return 0;
}