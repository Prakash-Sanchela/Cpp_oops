// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename newT>
class myclass{
private:
    newT *x;
public:
    myclass(newT* val = 0):x(val) {cout<<"myclass ctor "<<endl;}
    ~myclass(){cout<<"myclass ~dtor "<<endl;}
    
    void* operator new(size_t size){
        cout << "in new()"<<endl;
        void *ptr = malloc(size);
        if (!ptr){
            throw std::bad_alloc();
        }
        return ptr;
    }
    
    void operator delete(void* ptr)
    {
        cout << "in delete()"<<endl;
        free(ptr);
    }
};

int main() {
    myclass<int> *ptr = new myclass(10);
    delete ptr;
    return 0;
}
