# why do we use smart pointers
  1. Basic fundamental here is to avoid memory leaks.
  2. with traditional pointer, the problem is whatever memory is being allocated dynamically programmer has to take care about to free that memory after the use.
  3. Sometimes because of some issue delete/free is not happening and memory leak ocurs that results into variety of results like system crash, segmentation fault, application crash etc.
  4. Basically to remove the burden of delete the memory explicitely and handling memory in a perticular manner smart pointers are used.  
# Rvalue reference, move symantics with respect to unique_ptr
# advantage of using smart pointers
# types of smart pointers
# difference between smart pointers
# why auto_ptr deprecated from C++11 and completely removed in C++17?
  1. Lack of Clear Ownership Semantics
     std::auto_ptr uses transfer of ownership semantics when an object is copied or assigned.
     This means the source auto_ptr gives up ownership of the managed resource, and the destination auto_ptr takes ownership.
     After the assignment, p1 becomes nullptr.
     This behavior is non-intuitive and can lead to subtle bugs when used in code that assumes copying preserves the state 
     of both objects.
  3. Unsafe in Standard STL Containers
     

![image](https://github.com/user-attachments/assets/bb2d2e1e-1fb6-409d-8a59-793b45d15b5b)

