#include <iostream>
using namespace std;


class test{
private:
    int i;
public:
    test(int k){
        cout <<"In test ctor"<<endl;
        i=k;
    }
    void print(){cout <<"i = " <<i<<endl;}
    ~test()
    {
        cout <<"In test dtor"<<endl;
    }
};
template <class T>
class uniqueptr{
private:
    T *ptr;
public:
	// param ctor
    uniqueptr(T *p = nullptr):ptr(p){
        cout <<"ctor\n";
    }
    uniqueptr(const uniqueptr<T>& obj) = delete;
    uniqueptr& operator=(const uniqueptr<T>& obj) = delete;
    
	// move ctor
    uniqueptr(uniqueptr&& obj){
        cout <<"in move ctor\n";
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
	// move copy assignment operator
    uniqueptr& operator=(uniqueptr&& obj){
        cout <<"assignment operator\n";
        if (this != &obj){
            if (ptr){delete ptr;}
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }
	
	// operator overloading
    T* operator->(){return ptr;}
    T& operator*(){return *ptr;}
    
	//get res
    T* get() {return ptr;}
    
	void reset(T* newres = nullptr)
    {
        if (ptr){
            delete ptr;
        }
        ptr = newres;
    }
    
    ~uniqueptr()
    {
        cout <<"dctor\n"<<endl;
        if (ptr){
            delete ptr;
            ptr = NULL;
        }
    }
};

int main()
{
    
    //uniqueptr<int>ptr1(new int(2));
    //uniqueptr<int>ptr2(ptr1); //compile time error
    //uniqueptr<int> ptr3 = ptr1;
    //uniqueptr<int> ptr4(new int(500));
    //ptr4 = ptr3 // compile time error
    //uniqueptr<int> ptr3 = std::move(ptr1);   
    //ptr4 = std::move(ptr1);
    
    // in case if uniqueptr is a type of class
    //ptr1->fun();      //need to overload -> operator in class
    //cout<<*ptr<<endl; // need to overload * operator in class
    //ptr1.get();
    //ptr1.reset(new int(30));
    
    // implement the destructor
    uniqueptr<test> obj1(new test(15));
    obj1->print();
    //test *ptr = new test(10);
    return 0;
}
