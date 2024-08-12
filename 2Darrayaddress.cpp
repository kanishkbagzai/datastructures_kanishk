#include <iostream>
#include <string>
using namespace std;

int main() {
    string arrayType;
    int rows, cols, baseAddress;
    int elementSize;
    int i, j;
    string arrangement;

    // Input array type
    cout << "Enter array type (int, char, float, etc.): ";
    cin >> arrayType;

    // Determine element size based on array type
    if (arrayType == "int") {
        elementSize = sizeof(int);
    } else if (arrayType == "char") {
        elementSize = sizeof(char);
    } else if (arrayType == "float") {
        elementSize = sizeof(float);
    } else if (arrayType == "double") {
        elementSize = sizeof(double);
    } else {
        cout << "Unsupported array type." << endl;
        return 1;
    }

    // Input array size
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Input memory arrangement (ROW major or COLUMN major)
    cout << "Enter memory arrangement (ROW or COLUMN): ";
    cin >> arrangement;

    // Input base address of the array
    cout << "Enter base address of the array: ";
    cin >> baseAddress;

    // Input the index of the element whose address is to be calculated
    cout << "Enter the index (i, j) of the element: ";
    cin >> i >> j;

    // Calculate the address of the element
    int address;
    if (arrangement == "ROW" || arrangement == "row") {
        address = baseAddress + (i * cols + j) * elementSize;
    } else if (arrangement == "COLUMN" || arrangement == "column") {
        address = baseAddress + (j * rows + i) * elementSize;
    } else {
        cout << "Invalid memory arrangement specified." << endl;
        return 1;
    }

    // Output the address of the element
    cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;

    return 0;
}
