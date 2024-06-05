// implement own exception handling class
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class myException : public exception
{
private:
  string msg;
public:
  myException(const char* message): msg(message)
  {}
  // override the what() method
  const char* what() const throw()
  {
     return msg.c_str(); 
  }
};

int main()
{
  try{
    throw myException("this is my exception");
  }
  catch (myException e)
  {
    cout << "Caught an exception : " << e.what() <<endl;
  }
  return 0;
}
