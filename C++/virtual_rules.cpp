// 1. if in base class if we have at least one virtual function, 
//    vptr get's added to that class, also in derived class there's no separate vptr is being created,
//    as base class vptr get's derived to class B.
//    Every instance of class there will be separate vptr
// 2. compiler will create a static array called vtable.
//      - only created one time per class 
//      - array of function pointers pointing to virtual functions available in class.
//      - whichever class has virtual function in it, vtable is created for that class
class A
{
public :
  virtual void fun1();
};
class B:public A
{
public:
  void fun1();
};

