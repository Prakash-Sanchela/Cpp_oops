==============================C++11==============================================
C++11 introduced a significant number of new features and improvements to the C++ programming language, making it more powerful, efficient, and expressive. Below are some of the key features introduced in C++11:

### 1. **Auto Keyword**
- The `auto` keyword allows for type inference, meaning the compiler automatically deduces the type of a variable based on the initializer.
- This is especially useful for complex types like iterators or lambda expressions.

```cpp
auto x = 42;  // x is deduced to be of type int
auto y = 3.14; // y is deduced to be of type double
```

### 2. **Range-based For Loop**
- C++11 introduces a new syntax for iterating over containers, simplifying the loop structure.

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto value : vec) {
    std::cout << value << " ";
}
```

### 3. **Lambda Expressions**
- Lambda expressions allow for defining anonymous functions inline, making it easier to pass functions as arguments to algorithms.

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
```

### 4. **Smart Pointers (`std::unique_ptr`, `std::shared_ptr`)**
- C++11 introduces smart pointers, which help manage dynamic memory and avoid memory leaks. 
- `std::unique_ptr` is for exclusive ownership, and `std::shared_ptr` is for shared ownership.

```cpp
std::unique_ptr<int> p1 = std::make_unique<int>(10);
std::shared_ptr<int> p2 = std::make_shared<int>(20);
```

### 5. **nullptr**
- The `nullptr` keyword represents a null pointer constant. It is type-safe and can be used in place of `NULL` or `0` for pointer assignments.

```cpp
int* p = nullptr;  // nullptr is type-safe, unlike NULL or 0
```

### 6. **Move Semantics and Rvalue References**
- C++11 introduces **move semantics** to optimize the transfer of resources between objects.
- **Rvalue references** (`&&`) allow a function to distinguish between lvalues and rvalues, enabling efficient resource transfer (especially for containers).

```cpp
void foo(int&& x) { 
    std::cout << x << std::endl; 
}

int main() {
    int a = 10;
    foo(std::move(a));  // Transfer ownership without copying
}
```

### 7. **`std::thread` and Concurrency Support**
- C++11 introduces built-in support for multi-threading with the `std::thread` class and related synchronization tools like `std::mutex`, `std::lock`, and `std::condition_variable`.

```cpp
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from a thread!" << std::endl;
}

int main() {
    std::thread t(hello);  // Create a thread to run the hello function
    t.join();  // Wait for the thread to finish
    return 0;
}
```

### 8. **Type Aliases (`using`)**
- C++11 introduces the `using` keyword for type aliasing, which is a more readable alternative to `typedef`.

```cpp
using IntPtr = int*;  // Type alias for int pointer
IntPtr p = nullptr;
```

### 9. **`constexpr`**
- The `constexpr` keyword allows for **constant expressions**, enabling the evaluation of functions or variables at compile-time.

```cpp
constexpr int square(int x) { return x * x; }
int arr[square(5)];  // Array size is computed at compile-time
```

### 10. **Static Assertions (`static_assert`)**
- `static_assert` allows you to perform compile-time checks, throwing an error if the condition fails.

```cpp
static_assert(sizeof(int) == 4, "Integers must be 4 bytes");
```

### 11. **Uniform Initialization Syntax**
- C++11 introduces a uniform syntax for initializing variables, which avoids issues related to constructor overloads and makes code cleaner.

```cpp
int x{10};  // Uniform initialization syntax
std::vector<int> vec{1, 2, 3, 4, 5};
```

### 12. **`std::initializer_list`**
- `std::initializer_list` allows you to pass a list of values to a constructor or function, enabling easy initialization of containers or other objects.

```cpp
void print_list(std::initializer_list<int> list) {
    for (auto& val : list) {
        std::cout << val << " ";
    }
}

int main() {
    print_list({1, 2, 3, 4, 5});
}
```

### 13. **`decltype`**
- `decltype` is used to deduce the type of an expression, which is useful for writing template functions and other type-dependent code.

```cpp
int x = 10;
decltype(x) y = 20;  // y will be of type int
```

### 14. **`std::tuple`**
- C++11 introduces `std::tuple`, a fixed-size collection of heterogeneous objects, which allows you to store different types in a single object.

```cpp
#include <tuple>
std::tuple<int, double, std::string> t(1, 3.14, "Hello");
std::cout << std::get<0>(t) << std::endl;  // Access tuple elements by index
```

### 15. **`std::unique_lock` and `std::lock_guard`**
- These classes provide more flexible ways to manage mutexes, ensuring that locks are acquired and released in a controlled way, preventing race conditions and deadlocks.

```cpp
std::mutex mtx;
{
    std::lock_guard<std::mutex> lock(mtx);  // Automatically locks and unlocks the mutex
    // critical section
}
```

### 16. **`std::chrono` Library (Time Handling)**
- C++11 provides the `std::chrono` library for handling durations, clocks, and time points in a more efficient and type-safe way.

```cpp
#include <chrono>
using namespace std::chrono;

auto start = high_resolution_clock::now();
// Some operations
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
std::cout << "Duration: " << duration.count() << "ms\n";
```

### 17. **Delegating Constructors**
- C++11 allows a constructor to delegate its initialization to another constructor of the same class, reducing redundancy.

```cpp
class MyClass {
public:
    MyClass() : MyClass(0) {}  // Delegating constructor
    MyClass(int x) { std::cout << "Value: " << x << std::endl; }
};
```

### 18. **Move Constructors and Move Assignment Operators**
- In C++11, move semantics are enhanced with **move constructors** and **move assignment operators**, which enable efficient transfers of resources between objects.

```cpp
class MyClass {
public:
    MyClass(MyClass&& other) {  // Move constructor
        // Move resources from 'other' to this object
    }
};
```

### 19. **`std::function` and `std::bind`**
- `std::function` is a flexible, type-safe wrapper for function pointers, and `std::bind` allows you to bind arguments to functions, enabling easy function composition.

```cpp
#include <functional>
void greet(const std::string& name) { std::cout << "Hello, " << name << std::endl; }

int main() {
    std::function<void()> greet_func = std::bind(greet, "Alice");
    greet_func();  // Prints "Hello, Alice"
}
```

### Summary:
C++11 introduced many powerful features, including:
- **Type inference** (`auto`), **lambda expressions**, and **smart pointers**.
- **Concurrency** support with `std::thread` and synchronization tools.
- **Move semantics**, **rvalue references**, and **`std::unique_ptr`** for efficient resource management.
- **Static assertions**, **`constexpr`** for compile-time calculations, and better error checking.
- **Range-based for loops**, **`std::tuple`**, and **uniform initialization syntax**.

These features made C++ more modern, expressive, and efficient, encouraging better coding practices and performance optimizations.

==============================C++14==============================================
C++14 is an incremental update to C++11, which introduced several bug fixes, small improvements, and new features that made the language more convenient and expressive. While it doesn't have as many groundbreaking changes as C++11, it nonetheless provides valuable enhancements to the language. Here are the key features and improvements introduced in C++14:

### 1. **Lambda Expressions Enhancements**
C++14 made a few improvements to **lambda expressions** introduced in C++11, making them more powerful.

- **Generic lambdas**: C++14 allows lambda expressions to have **auto** in their parameter types, allowing lambdas to be more generic.

```cpp
auto add = [](auto a, auto b) { return a + b; };
std::cout << add(3, 4) << std::endl;  // Outputs 7
std::cout << add(3.5, 4.5) << std::endl;  // Outputs 8.0
```

- **Returning from lambda**: C++14 allows **lambda expressions** to explicitly specify a return type using the trailing return type syntax, even when returning an expression that isn't immediately obvious.

```cpp
auto multiply = [](int a, int b) -> int { return a * b; };
std::cout << multiply(3, 4) << std::endl;  // Outputs 12
```

- **Capture by reference in lambda**: In C++14, you can **capture by reference** a variable declared inside the lambda expression's body.

```cpp
int x = 10;
auto add_x = [x]() { return x + 5; };  // Capture x by value
std::cout << add_x() << std::endl;  // Outputs 15
```

### 2. **`std::make_unique`**
In C++14, the **`std::make_unique`** function was added to make it easier to create `std::unique_ptr` objects.

- **Before C++14**, you would need to use the `new` operator to create a `unique_ptr`:
```cpp
std::unique_ptr<int> ptr(new int(10));
```
- **In C++14**, `std::make_unique` simplifies it:
```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);
```
`std::make_unique` is safer because it prevents memory leaks caused by an exception being thrown between `new` and the `unique_ptr` creation.

### 3. **Return Type Deduction for Normal Functions**
C++14 allows for **automatic return type deduction** in non-lambda functions, making it similar to how lambdas deduce their return type.

- **C++14** enables return type deduction for regular functions:

```cpp
auto add(int a, int b) {
    return a + b;
}

std::cout << add(2, 3) << std::endl;  // Outputs 5
```

This feature makes the function declaration simpler and more flexible. The return type is deduced automatically based on the return statement.

### 4. **`std::shared_ptr` Improvements**
C++14 improved `std::shared_ptr` with a new member function:

- **`std::shared_ptr::reset()`**: Now, you can call `reset()` with a custom deleter, which wasn't allowed in C++11.

```cpp
auto ptr = std::make_shared<int>(10);
ptr.reset(new int(20));  // Reset with a new object
```

### 5. **Binary Literals**
C++14 introduced **binary literals**, allowing you to specify integer values in binary form, which is useful for bitwise operations and low-level programming.

```cpp
int binary = 0b101010;  // Binary literal: 42 in decimal
std::cout << binary << std::endl;  // Outputs 42
```

### 6. **Digit Separators for Literals**
C++14 introduced a new feature that allows you to use an apostrophe (`'`) as a **digit separator** in numeric literals for better readability.

```cpp
int million = 1'000'000;  // Using apostrophes to separate digits
std::cout << million << std::endl;  // Outputs 1000000
```

This feature helps with the readability of large numbers, making it easier to spot digits in large values (like `1'000'000` for one million).

### 7. **`std::swap` for User-Defined Types**
C++14 improves the **`std::swap`** algorithm by providing a more efficient swap mechanism for user-defined types. You can now implement **`std::swap`** for your types directly, which can lead to more efficient swapping behavior.

```cpp
class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
    
    // Swap implementation for MyClass
    friend void swap(MyClass& first, MyClass& second) {
        using std::swap;
        swap(first.value, second.value);
    }
};
```

### 8. **`std::get` for `std::tuple`**
C++14 allows using `std::get` with **non-constant expressions** to access elements of a `std::tuple`. This is useful when the index is computed at runtime.

```cpp
std::tuple<int, double, char> t(10, 3.14, 'a');
int i = 1;
std::cout << std::get<i>(t) << std::endl;  // Outputs 3.14 (the second element)
```

### 9. **Generalized `constexpr`**
C++14 enhanced **`constexpr`** functions, allowing them to perform more operations at compile-time, including the use of **`if` statements** and **loops** inside `constexpr` functions.

```cpp
constexpr int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

std::cout << factorial(5) << std::endl;  // Outputs 120
```

This makes `constexpr` more powerful, enabling complex compile-time computations.

### 10. **`std::chrono` Improvements**
C++14 added a few improvements to the `std::chrono` library:

- **`std::chrono::duration_cast`** now works with **different time units** more easily.
- **`std::chrono::system_clock`** now has better support for real-time durations.

### 11. **`std::make_shared` Improvements**
C++14 added improvements to **`std::make_shared`**, making it more efficient in certain use cases by reducing memory allocation overhead.

### 12. **User-defined Literals Enhancements**
C++14 expanded **user-defined literals** to allow **literals with no suffix**, which was a limitation in C++11. You can now define custom literal suffixes for types and operations that make code more readable and intuitive.

```cpp
constexpr long double operator"" _km(long double x) { return x * 1000; }
constexpr long double operator"" _m(long double x) { return x; }

int main() {
    std::cout << 10.0_km << std::endl;  // 10 kilometers in meters (10000.0)
}
```

### 13. **Improved Template Type Deduction**
C++14 introduced more flexible template type deduction. Now, **`std::vector`** and other containers can deduce the element type from the constructor argument type even if the element type is explicitly stated.

```cpp
std::vector v = {1, 2, 3};  // Deduction guides deduce the vector type (std::vector<int>)
```

### 14. **`std::integral_constant` Improvements**
C++14 introduces enhancements to the `std::integral_constant` class template, improving the ability to perform metaprogramming tasks that depend on constant values.

### 15. **Removed Deprecated Features**
Several features deprecated in C++11 or earlier were removed, including:
- `std::auto_ptr`, which was replaced by `std::unique_ptr`.
- Several C-style features that were less efficient or error-prone.

### Conclusion:
C++14 is an incremental update to C++11 that refines and improves several existing features. Key highlights include:
- Enhancements to **lambda expressions**, including generic lambdas and **auto** in lambda parameters.
- The addition of **`std::make_unique`**, improving memory management.
- Improvements in **`constexpr`** and **`std::chrono`**.
- New features like **binary literals**, **digit separators**, and user-defined literals.

While C++14 doesn’t introduce as many major new features as C++11, it makes C++ a more robust and user-friendly language by refining the tools introduced in the previous standard.
