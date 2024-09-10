#include <iostream>
using namespace std;
#define PRAKASH(san) ((char *)(&san + 1) - (char*)(&san))
int main()
{
  int *p;
  cout << "sizeof : "<<PRAKASH(ptr)<<endl;
}
