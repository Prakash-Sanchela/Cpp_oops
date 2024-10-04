#include <iostream>

using namespace std;

int main()
{
  int row = 4;
  int col = 3;

  int **ptr = new int*[row];
  for (int i = 0; i<col;i++)
    ptr[i] = new int[col];

  int num = 10;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; i < col; j++)
    {
      ptr[i][j] = num;
      num += 5;
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; i < col; j++)
    {
      cout << ptr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
