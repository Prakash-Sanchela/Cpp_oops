# why do we use smart pointers
  1. Basic fundamental here is to avoid memory leaks.
  2. with traditional pointer, the problem is whatever memory is being allocated dynamically programmer has to take care about to free that memory after the use.
  3. Sometimes because of some issue delete/free is not happening and memory leak ocurs that results into variety of results like system crash, segmentation fault, application crash etc.
  4. Basically to remove the burden of delete the memory explicitely and handling memory in a perticular manner smart pointers are used.  
# Rvalue reference, move symantics with respect to unique_ptr
# advantage of using smart pointers
# types of smart pointers
# difference between smart pointers
