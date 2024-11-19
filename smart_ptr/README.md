# Why do we use smart pointers
  1. Basic fundamental here is to avoid memory leaks.
  2. with traditional pointer, the problem is whatever memory is being allocated dynamically programmer has to take care about to free that memory after the use.
  3. Sometimes because of some issue delete/free is not happening and memory leak ocurs that results into variety of results like system crash, segmentation fault, application crash etc.
  4. Basically to remove the burden of delete the memory explicitely and handling memory in a perticular manner smart pointers are used.  
# Types of smart pointers
  - weak_ptr
  - shared_ptr
  - unique_ptr
  - Check make_unique & make_shared
# Difference between smart pointers
# What is RAII
  Resource Acquisition Is Initialization or RAII, is a C++ programming technique, which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.
  Move semantics enable the transfer of resources and ownership between objects, inside and outside containers, and across threads, while ensuring resource safety.
  In addition, the standard library offers several RAII wrappers to manage user-provided resources:
std::unique_ptr and std::shared_ptr through **std::make_unique** and **std::make_shared** to manage dynamically-allocated memory;
std::lock_guard, std::unique_lock, std::shared_lock to manage mutexes.
# What are l-value and r-value references.
# What is move semantics, and why is it used.
# why auto_ptr deprecated from C++11 and completely removed in C++17?
  1. Lack of Clear Ownership Semantics
     std::auto_ptr uses transfer of ownership semantics when an object is copied or assigned.
     This means the source auto_ptr gives up ownership of the managed resource, and the destination auto_ptr takes ownership.
     After the assignment, p1 becomes nullptr.
     This behavior is non-intuitive and can lead to subtle bugs when used in code that assumes copying preserves the state 
     of both objects.
  3. Unsafe in Standard STL Containers
     

![image](https://github.com/user-attachments/assets/bb2d2e1e-1fb6-409d-8a59-793b45d15b5b)

