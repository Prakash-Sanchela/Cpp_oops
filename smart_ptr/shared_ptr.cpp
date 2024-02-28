// shared_ptr
#include <iostream>
using namespace std;

template<typename T>
class sharedptr{
private:
    T* res;
    // we need to use int* because
    // 1. int counter -> this will be object specific, if another pointer points to already allocated memory the counter is belongs to 
    //    that perticular object so both counter will be different and value will be 1 only. 
    // 2. static int counter -> this will also not work becasue static is common to all the object but what 
    //    happen in case of one objects points to one memory location and another points to another memory location
    //    so even for different mem location counter will get's incresed and that's not what we want
    // 3. int *ptr -> now this solution what it will do it will keep a pointer which points to the memory allocated to *res with one integer. 
    //    so everytime for same object we can use this pointer to increament and decreament the counter as for res and counter different memory is getting created

    int *counter;
    
    void incrementCounter()
    {
        if (counter)
            (*counter)++;
    }
    
    void decrementCounter()
    {
        if(counter){
            (*counter)--;
            if ((*counter) == 0){
                if (res) {
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
                }
            }
        }
    }
public:
    // default ctor 
    sharedptr(T* ptr = nullptr):res(ptr), counter(new int(1)){
        cout << "param ctor\n";
    }
    //copy constructor
    sharedptr(const sharedptr<T>& ptr)
    {
        cout << "copy ctor\n";
        res = ptr.res;
        counter = ptr.counter;
        incrementCounter();
    }
    
    //copy move ctor
    sharedptr(sharedptr&& ptr)
    {
        cout << "move ctor\n";
        res = ptr.res;
        counter = ptr.counter;
        ptr.res = NULL;
        ptr.counter = NULL;
    }
    
    // copy assignment operator
    sharedptr& operator=(const sharedptr<T>& ptr)
    {
        // here we need to decreament the counter for calling pointer(ptr3) and
        // increament the counter for the object which is being assigned(ptr2)
        cout << "copy assignment operator\n";
        if(this != &ptr)
        {
            decrementCounter();
            res = ptr.res;
            counter = ptr.counter;
            incrementCounter();
        }
        return *this;
    }
    
    // copy move assignment operator
    sharedptr& operator=(sharedptr&& ptr)
    {
        cout << "move copy assignment operator\n";
        if (this != & ptr) {
            decrementCounter();
            res = ptr.res;
            counter = ptr.counter;
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }
        return *this;
    }
    
    void reset(T* newRes){
        decrementCounter();
        res = newRes.res;
        counter = new int(1);
    }
    
    int get_count(){
        if (counter)
            return *counter;
        return -1;
    }
    
    T* operator->(){ return res; }
    T& operator*() { return *res; }
    
    T* get(){ return res;}
    
    ~sharedptr(){
        cout << "dtor\n";
        decrementCounter();
    }
};

int main()
{
    sharedptr<int> ptr1;
    sharedptr<int> ptr2 = new int(10); // param ctor
    sharedptr<int> ptr3(new int(20)); // param ctor
    sharedptr<int> ptr4(ptr2); // or ptr3 = ptr2 : copy ctor 
    sharedptr<int> ptr5 = ptr2; // copy ctor
    ptr5 = ptr3; // copy assignment operator
    //sharedptr<int> ptr5(std::move(ptr1)); // move copy constructor
    //ptr2 = std::move(ptr3); // move copy assignment operator
    
    //ptr1.reset(); // reset or set it to NULL
    //ptr1.reset(new int(60));
    
    //ptr1->fun(); // applicable for user defined data type like class. done through -> operator
    cout << (*ptr3)<<endl; // implementing * operator
    
    //ptr1.get(); // raw pointer
    cout << "counter : " << ptr2.get_count()<<endl; //number of objects pointing to the same resource
    //dtor
    
    return 0;
}
