// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    //std::cout << "Try programiz.pro";
    int row = 4;
    int col = 3;
    
    int **ptr = new int*[row];
    for(int i = 0; i< row; i++)
    {
        ptr[i] = new int[col];
    }
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ptr[i][j] = num++;  // Assigning values
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ptr[i][j];  // Assigning values
        }
        cout <<endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete[]arr[i];  // Assigning values
    }
    delete []arr;
    return 0;
}
