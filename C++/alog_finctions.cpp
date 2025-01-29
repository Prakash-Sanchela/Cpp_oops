In C++, the **`<algorithm>`** header provides a wide range of **standard algorithms** that can be used with containers such as arrays, vectors, lists, etc. These algorithms are powerful and allow for a variety of common operations like searching, sorting, modifying, and manipulating elements in a container.

Here’s a list of the **most commonly used algorithms** available in the **`<algorithm>`** header:

### 1. **Sorting Algorithms**
- **`std::sort`**: Sorts a range of elements in ascending order.
  ```cpp
  std::vector<int> vec = {4, 1, 3, 9, 2};
  std::sort(vec.begin(), vec.end());  // Sorts in ascending order
  ```

- **`std::stable_sort`**: Sorts a range of elements while preserving the relative order of equal elements.
  ```cpp
  std::stable_sort(vec.begin(), vec.end());
  ```

- **`std::partial_sort`**: Sorts part of a range. It sorts the first `n` elements of a range.
  ```cpp
  std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
  ```

- **`std::nth_element`**: Reorders the elements such that the element at the nth position is in the correct position, with all smaller elements before it and all larger elements after it.
  ```cpp
  std::nth_element(vec.begin(), vec.begin() + 2, vec.end());  // 2nd element will be in correct position
  ```

- **`std::reverse`**: Reverses the order of elements in a range.
  ```cpp
  std::reverse(vec.begin(), vec.end());
  ```

### 2. **Searching Algorithms**
- **`std::find`**: Searches for a value in a range and returns an iterator to the first occurrence.
  ```cpp
  auto it = std::find(vec.begin(), vec.end(), 3);  // Find first occurrence of 3
  ```

- **`std::binary_search`**: Checks if a value exists in a sorted range (returns a boolean).
  ```cpp
  bool found = std::binary_search(vec.begin(), vec.end(), 3);
  ```

- **`std::find_if`**: Searches for the first element satisfying a predicate.
  ```cpp
  auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 5; });
  ```

- **`std::lower_bound`**: Finds the first position in a sorted range where a value can be inserted without violating the order.
  ```cpp
  auto it = std::lower_bound(vec.begin(), vec.end(), 3);
  ```

- **`std::upper_bound`**: Finds the first position in a sorted range where a value would go if inserted at the end.
  ```cpp
  auto it = std::upper_bound(vec.begin(), vec.end(), 3);
  ```

### 3. **Modification Algorithms**
- **`std::copy`**: Copies elements from one range to another.
  ```cpp
  std::vector<int> vec_copy;
  std::copy(vec.begin(), vec.end(), std::back_inserter(vec_copy));
  ```

- **`std::transform`**: Applies a function to each element in a range and stores the result in another range.
  ```cpp
  std::vector<int> transformed;
  std::transform(vec.begin(), vec.end(), std::back_inserter(transformed), [](int x) { return x * 2; });
  ```

- **`std::replace`**: Replaces all occurrences of a given value with another value.
  ```cpp
  std::replace(vec.begin(), vec.end(), 3, 7);  // Replace all 3's with 7
  ```

- **`std::replace_if`**: Replaces all elements satisfying a predicate with a given value.
  ```cpp
  std::replace_if(vec.begin(), vec.end(), [](int x) { return x < 5; }, 0);
  ```

- **`std::fill`**: Fills a range with a given value.
  ```cpp
  std::fill(vec.begin(), vec.end(), 5);  // Fill entire vector with 5
  ```

- **`std::fill_n`**: Fills a specified number of elements with a given value.
  ```cpp
  std::fill_n(vec.begin(), 3, 0);  // Fill first 3 elements with 0
  ```

### 4. **Counting Algorithms**
- **`std::count`**: Counts the occurrences of a value in a range.
  ```cpp
  int count = std::count(vec.begin(), vec.end(), 3);
  ```

- **`std::count_if`**: Counts the number of elements satisfying a predicate.
  ```cpp
  int count = std::count_if(vec.begin(), vec.end(), [](int x) { return x > 5; });
  ```

### 5. **Partitioning Algorithms**
- **`std::partition`**: Reorders the elements so that all elements satisfying a predicate appear before those that do not.
  ```cpp
  std::partition(vec.begin(), vec.end(), [](int x) { return x > 3; });
  ```

- **`std::stable_partition`**: Similar to `std::partition`, but it preserves the relative order of elements.
  ```cpp
  std::stable_partition(vec.begin(), vec.end(), [](int x) { return x > 3; });
  ```

### 6. **Set Operations**
- **`std::set_union`**: Computes the union of two sorted ranges.
  ```cpp
  std::vector<int> result;
  std::set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
  ```

- **`std::set_intersection`**: Computes the intersection of two sorted ranges.
  ```cpp
  std::vector<int> result;
  std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
  ```

- **`std::set_difference`**: Computes the difference between two sorted ranges.
  ```cpp
  std::vector<int> result;
  std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
  ```

- **`std::set_symmetric_difference`**: Computes the symmetric difference between two sorted ranges.
  ```cpp
  std::vector<int> result;
  std::set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
  ```

### 7. **Min/Max Algorithms**
- **`std::min`**: Returns the smaller of two values.
  ```cpp
  int min_val = std::min(3, 5);  // Returns 3
  ```

- **`std::max`**: Returns the larger of two values.
  ```cpp
  int max_val = std::max(3, 5);  // Returns 5
  ```

- **`std::min_element`**: Returns an iterator to the smallest element in a range.
  ```cpp
  auto it = std::min_element(vec.begin(), vec.end());
  ```

- **`std::max_element`**: Returns an iterator to the largest element in a range.
  ```cpp
  auto it = std::max_element(vec.begin(), vec.end());
  ```

- **`std::minmax`**: Returns both the minimum and maximum values in a range.
  ```cpp
  auto result = std::minmax(3, 5);  // Returns a pair (3, 5)
  ```

### 8. **Heap Operations**
- **`std::make_heap`**: Converts a range into a heap.
  ```cpp
  std::make_heap(vec.begin(), vec.end());
  ```

- **`std::push_heap`**: Adds a new element to an existing heap.
  ```cpp
  vec.push_back(7);
  std::push_heap(vec.begin(), vec.end());
  ```

- **`std::pop_heap`**: Removes the top element from a heap.
  ```cpp
  std::pop_heap(vec.begin(), vec.end());
  vec.pop_back();
  ```

- **`std::sort_heap`**: Sorts a heap.
  ```cpp
  std::sort_heap(vec.begin(), vec.end());
  ```

### 9. **Other Useful Algorithms**
- **`std::is_sorted`**: Checks if a range is sorted.
  ```cpp
  bool sorted = std::is_sorted(vec.begin(), vec.end());
  ```

- **`std::shuffle`**: Randomly shuffles the elements of a range.
  ```cpp
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(vec.begin(), vec.end(), g);
  ```

- **`std::rotate`**: Rotates the elements in a range.
  ```cpp
  std::rotate(vec.begin(), vec.begin() + 2, vec.end());  // Rotates by 2 positions
  ```

### Conclusion:
The **`<algorithm>`** header in C++ provides a rich set of functions to manipulate and process data in containers. These functions can be used to perform tasks like sorting, searching, modifying elements, partitioning data, and much more, greatly simplifying everyday programming tasks. Understanding and utilizing these algorithms allows for cleaner, more efficient, and more readable C++ code.
