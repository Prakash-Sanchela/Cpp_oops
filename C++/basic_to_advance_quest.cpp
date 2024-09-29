//==============BASIC C++===================
// oops, polymorphism, static function and static variable,
virtual functions, constructor, destructor, copy constructor,
inheritance, abstraction, polymorphism, operator overloading,
function overloading vs function overriding, type casting
==========================================
Compilation steps
		i. Pre-processor
		ii. Translator 
		iii. Assembler
		iv. Linker
How char is stored in 1 byte of memory in below program
		i. Char ch;
		ii. Char ch = 'a';   ans : it's ASCII stored 
How 0 will be stores as char and as an integer
		i. Char ch = 0 // as integer
		ii. Char ch = '0' // as character
How -1 is getting stored as binary, ans : 2's complement of 1.
Memory organization is C
		i. Stack
		ii. Heap
		iii. Data
		iv. Code
Is head and stack upgrowing/downgrading. Is there any standard way to define
Storage classes
Printf vs sprintf vs fprintf
Macros vs functions
Calloc vs malloc
What causes memory leak? Which tools and techniques, you will use to identify and fix memory leaks?
Memcpy vs memmove
Dangling pointer & segmentation fault, how will you deal with it. 
Call by value & Call by reference. 

Why we cannot use ‘this’ pointer in static member function?
Explain any use case or example when you will prefer to use static data members and static member functions.
For C++ dynamic binding, how ‘virtual pointer’ / ‘vptr’ gets initialized?
If memory allocation using new fails in C++, how to handle it gracefully?
What are issues if we mix new and free in C++?
What is the size of empty class in C++ & Empty structure in C?
Is it possible to defined nested classes in C++?
What is Friend Class in C++?
How ‘Protected’ access specifier/modifier is used in C++ class?
Which all different modes of inheritance C++ supports? Please elaborate details about those
Can we define virtual constructor in C++?
Can we define a pure virtual destructor in C++?
How to define a catch block to catch all exceptions.
What happens when realloc fails. How to handle it gracefully 
Can protected members in base class accessible from derived class
class Relationship
	Has A relationship & IS A relationship
	Inheritance vs composition
	Aggregation and composition
Casting in C++
	static_cast
	dynamic_cast
	const_cast
	reinterprete_cast
SOLID principles



//=============Advance C++==================
//array, vector, map, set, multimap, multiset,
// unordered_map, unordered_set, uniques_ptr,
// shared_ptr, weak_ptr, auto_ptr, lambda functions etc.
//==========================================

 Casting in c++
 Smart pointer (unique pointer and share pointer)
 Initializer list
 how const impact in variable/function/argument/copy constructor/object.
 how static impact.
 serialization and de-serializtion in Binary tree.
 
 minimum platform problem.
 implement vector/map/list container
 Implement string class.
 Implement own samrt pointer.
 
 
 singleton class design with synchronization.
 
 how to find hang issue using core file.
 
OS
 diffrence between thread and process.
 What happen if a non-recursive mutex is locked more than once.
 Thead blocking on mutex/semaphore
 Creitical section and how to solve this.
 Semaphore and its type.
 
 Print number in sequence using thread synchronization.

DS
 Smallest subarray
 kth largest sum
 lowest cooman ancester.
 implement a stack which will support O(1). push pop find middle delete middle.
 bfs and dfs.
 pattern matching algorithm.
 sorting and searching algo  
 thread synchronization.

Design Pattern
 Observer
 chain of responsibility.
 factory/ abstract
 Factory vs strategy
 Singlton
