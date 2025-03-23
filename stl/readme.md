1. vector vs dequeue
2. Disadvantage of vector
     - Expensive reallocation (lot of construction and destruction)
     - Requires continues memory
3. When to use vector and when to use deque?
    - Vector : if performance is important 
    - deque - when you want to push at front continuesly
   1. Element type
        When the element type is not trivial (builtin data types), deque is not much less efficient then vector
   2. Memory availibility
        When there's a problem of memory availibility, can consider using deque. (for e.g. embedded systems)
   3. Frequency of unpredictable growth
        When growth of container is completely unpredictable, we should consider the deque. 
