// pointers test cpp

void changePointer(int*** ptr) { *ptr = new int*[5]; }

int main() {
    int** ptr;
    changePointer(&ptr);
    return 0;
}