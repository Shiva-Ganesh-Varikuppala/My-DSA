

# Recursion Notes

## What is Recursion?

Recursion is a programming technique where a function calls itself.

A recursive function solves a problem by:

1. Solving smaller subproblems
2. Calling itself repeatedly
3. Stopping at a base case

---

# Real Life Examples

- Mirrors facing each other
- Russian dolls
- Folder inside folder
- Tree branches
- Function call stack

---

# Basic Structure of Recursion

```cpp
void fun() {

    // Base Case

    // Recursive Call
    fun();
}
```

---

# Important Components of Recursion

| Component | Meaning |
|---|---|
| Base Case | Stopping condition |
| Recursive Call | Function calling itself |
| Recursive Relation | Problem reduced into smaller version |
| Stack Frame | Memory allocated for each call |

---

# Base Case

The condition where recursion stops.

Without base case:

```text
Infinite Recursion
```

which causes:

```text
Stack Overflow
```

---

# Simple Recursive Function

```cpp
#include<iostream>
using namespace std;

void print(int n) {

    if(n == 0)
        return;

    cout << n << " ";

    print(n - 1);
}

int main() {
    print(5);
}
```

Output:

```text
5 4 3 2 1
```

---

# Recursive Flow

```text
print(5)
→ print(4)
→ print(3)
→ print(2)
→ print(1)
→ print(0)
```

Then functions return back.

---

# Call Stack

Every recursive call is stored in:

```text
Call Stack
```

Each function call gets:

- Parameters
- Local variables
- Return address

---

# Stack Overflow

Too many recursive calls can exceed stack memory.

Example:

```cpp
fun() {
    fun();
}
```

Causes:

```text
Stack Overflow Error
```

---

# Recursive Tree

Recursion can be visualized as a tree.

Example:

```cpp
fun(n-1);
fun(n-1);
```

creates branching recursion.

---

# Recursive Functions Categories

---

## 1. Direct Recursion

Function directly calls itself.

```cpp
fun() {
    fun();
}
```

---

## 2. Indirect Recursion

Functions call each other.

```cpp
fun1() → fun2()
fun2() → fun1()
```

---

## 3. Tail Recursion

Recursive call is last operation.

```cpp
void fun(int n) {

    if(n == 0)
        return;

    fun(n - 1);
}
```

---

## 4. Head Recursion

Recursive call happens first.

```cpp
void fun(int n) {

    if(n == 0)
        return;

    fun(n - 1);

    cout << n;
}
```

---

## 5. Tree Recursion

Multiple recursive calls.

```cpp
fib(n-1) + fib(n-2)
```

---

# Tail vs Head Recursion

| Tail Recursion | Head Recursion |
|---|---|
| Work before recursive call | Work after recursive call |
| Easier optimization | Harder optimization |
| Sometimes converted to loop | Uses stack heavily |

---

# Factorial Using Recursion

```cpp
#include<iostream>
using namespace std;

int factorial(int n) {

    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

---

# Recursive Relation of Factorial

```text
factorial(n) = n × factorial(n-1)
```

---

# Fibonacci Using Recursion

```cpp
#include<iostream>
using namespace std;

int fib(int n) {

    if(n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
```

---

# Fibonacci Recursion Tree

```text
fib(5)
├── fib(4)
│   ├── fib(3)
│   └── fib(2)
└── fib(3)
```

---

# Time Complexity of Fibonacci Recursion

```text
O(2ⁿ)
```

Very inefficient due to repeated calculations.

---

# Space Complexity of Recursion

Depends on recursion depth.

Example:

```cpp
fun(n-1)
```

Depth:

```text
n
```

Space Complexity:

```text
O(n)
```

---

# Recursion vs Iteration

| Recursion | Iteration |
|---|---|
| Uses function calls | Uses loops |
| Uses stack memory | Usually O(1) space |
| Cleaner for trees/graphs | Faster usually |
| Easier divide-and-conquer | Better memory efficiency |

---

# Advantages of Recursion

- Cleaner code
- Elegant solutions
- Useful in trees/graphs
- Divide and conquer
- Backtracking problems

---

# Disadvantages of Recursion

- Stack overflow risk
- Extra memory usage
- Slower due to function calls
- Harder debugging sometimes

---

# When to Use Recursion

Use recursion when problem naturally divides into subproblems.

Examples:

- Trees
- Graph DFS
- Backtracking
- Divide and Conquer
- Dynamic Programming

---

# Binary Search Using Recursion

```cpp
#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {

    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(arr[mid] == target)
        return mid;

    if(arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);

    return binarySearch(arr, mid + 1, right, target);
}
```

---

# Recursion in Trees

Tree traversal is naturally recursive.

Example:

```cpp
void inorder(Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
```

---

# Backtracking

Recursion + Undo choices.

Examples:

- N Queens
- Sudoku Solver
- Maze Problems
- Permutations

---

# Recursive Backtracking Pattern

```cpp
void solve() {

    if(base_case)
        return;

    // choose

    solve();

    // undo
}
```

---

# Divide and Conquer

Problem divided into smaller independent parts.

Examples:

- Merge Sort
- Quick Sort
- Binary Search

---

# Merge Sort Recurrence

```text
T(n) = 2T(n/2) + n
```

Complexity:

```text
O(n log n)
```

---

# Memoization

Optimization technique storing recursive results.

Avoids repeated calculations.

---

# Fibonacci with Memoization

```cpp
#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(100, -1);

int fib(int n) {

    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}
```

---

# Complexity Improvement with DP

| Method | Complexity |
|---|---|
| Normal Fibonacci | O(2ⁿ) |
| Memoized Fibonacci | O(n) |

---

# Recursion Stack Visualization

Example:

```cpp
fun(3)
```

Stack:

```text
fun(3)
fun(2)
fun(1)
fun(0)
```

Functions return in reverse order.

---

# Important Recursive Problems

1. Factorial
2. Fibonacci
3. Binary Search
4. Tower of Hanoi
5. Generate Subsequences
6. Generate Permutations
7. N Queens
8. Sudoku Solver
9. Maze Problems
10. Tree Traversals

---

# Tower of Hanoi

Classic recursion problem.

Formula:

```text
Moves = 2ⁿ - 1
```

---

# Common Mistakes

---

## Mistake 1

Missing base case.

---

## Mistake 2

Incorrect recursive relation.

---

## Mistake 3

Too much recursion depth.

---

## Mistake 4

Repeated calculations without memoization.

---

# Real Interview Insights

Interviewers expect:

- Base case understanding
- Recursive thinking
- Stack understanding
- Recursion tree analysis
- Optimization using DP
- Backtracking knowledge

---

# Golden Rules of Recursion

1. Every recursive function needs a base case
2. Recursive calls should move toward base case
3. Think in smaller subproblems
4. Watch recursion depth
5. Memoization optimizes recursion heavily

---

# Complexity Summary

| Problem | Time | Space |
|---|---|---|
| Factorial | O(n) | O(n) |
| Binary Search | O(log n) | O(log n) |
| Fibonacci Recursive | O(2ⁿ) | O(n) |
| Merge Sort | O(n log n) | O(log n) |

---

# Final Summary

Recursion is one of the most important concepts in DSA.

Most important concepts:

```text
Base Case
Recursive Call
Call Stack
Tail Recursion
Backtracking
Memoization
Divide and Conquer
```

Recursion is heavily used in:

- Trees
- Graphs
- Dynamic Programming
- Backtracking
- Divide and Conquer Algorithms
- Competitive Programming