	• STL is a standard template library overview 

	• At the core of the C++ STL are following three well-structured components
		○ Containers
			§ Array
			§ Vector
			§ Map
			§ Queue
			§ Stack
			§ List
			§ Set
			§ Multimap
			
		○ Algorithm
			§ Sorting
			§ Searching
			§ Important STL algorithm
			§ Useful array algorithms
			§ Partition operation
		○ Iterators
			§ Iterators
			
	
	• Containers
		○ Containers are used to manage collections of object of a certain kind
		○ Container library in STL provide containers that are used to create data structures like Arrays, linked list, trees etc.
		○ These containers are generic, they can hold elements of any kind of data types.
		
		○ Examples of Containers:
		○ Vector : Vector is a class
			§ Vector can be used for creating dynamic arrays of char, integer, float and other types.
		○ Containers is used to hold the data.

	• Algorithms
		○ Algorithms act on containers. They provide the means by which you will perform initialization, sorting, searching and transforming the contains of the containers 
		○ Algorithms library contains built in function that performs the complex algorithms on the data structures.

		○ Examples of Algorithms:
			§ One can reverse a range with reverse() function, sort a range with sort() function, search in a range of with binary_search() and so on.
			§ Algorithms library provides abstraction, i.e you don't necessarily need to know how the algorithm works.
	
	• Iterators
		○ Iterators ( repatriations )are used to steps through the elements of collections of objects. These collections may be containers or subset of containers.
		○ Iterators in STL are used to point to the containers.
		○ Iterators actually act as a bridge  between containers and algorithms.
		○ Iterators is the concept which is implemented by pointers which point out the data into the containers.

		○ Examples :
			§ Sort() algorithm have two parameters, starting iterator and ending iterator, now sort() compares the elements pointed by each of these iterators and arrange them in sorted order, thus it does not matter what is the type of containers and same sort() can be used on different types of containers.
