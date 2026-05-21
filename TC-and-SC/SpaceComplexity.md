# Space Complexity Notes

## What is Space Complexity?

Space Complexity measures how much memory an algorithm uses as input size increases.

It includes:

- Variables
- Arrays
- Objects
- Function call stack
- Dynamic memory allocation
- Recursion stack

---

# Why Space Complexity Matters

Even if an algorithm is fast, it may fail because of:

- Memory Limit Exceeded (MLE)
- Stack Overflow
- Excessive RAM usage

Efficient programs should optimize:

```text
Time + Space
```

---

# Components of Space Complexity

Total Space Complexity:

```text
Space Complexity = Input Space + Auxiliary Space
```

---

# 1. Input Space

Memory required to store input.

Example:

```cpp
int arr[n];
```

Input array itself takes:

```text
O(n)
```

---

# 2. Auxiliary Space

Extra memory used by algorithm excluding input.

Example:

```cpp
int sum = 0;
```

Auxiliary space:

```text
O(1)
```

---

# Important Difference

| Type | Meaning |
|---|---|
| Space Complexity | Total memory used |
| Auxiliary Space | Extra memory only |

---

# Constant Space — O(1)

Memory does not grow with input size.

Example:

```cpp
int sum = 0;
int maxVal = 0;
```

Only fixed variables used.

---

# Linear Space — O(n)

Memory grows proportionally with input.

Example:

```cpp
int temp[n];
```

Space:

```text
O(n)
```

---

# Quadratic Space — O(n²)

Example:

```cpp
int matrix[n][n];
```

Space:

```text
n × n = n²
```

---

# Examples of Space Complexity

---

## Example 1

```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
```

Auxiliary Space:

```text
O(1)
```

Because only variables are used.

---

## Example 2

```cpp
vector<int> temp(n);
```

Auxiliary Space:

```text
O(n)
```

---

## Example 3

```cpp
int dp[n][n];
```

Auxiliary Space:

```text
O(n²)
```

---

# Space Complexity of Arrays

| Structure | Space Complexity |
|---|---|
| 1D Array | O(n) |
| 2D Matrix | O(n²) |
| 3D Matrix | O(n³) |

---

# Space Complexity of Recursion

Very important topic.

Each recursive call uses memory in stack.

---

# Recursion Stack Memory

Every function call stores:

- Parameters
- Local variables
- Return address
- Function state

Stored inside:

```text
Call Stack
```

---

# Example: Recursive Function

```cpp
void fun(int n) {
    if(n == 0) return;
    fun(n - 1);
}
```

Recursive calls:

```text
n → n-1 → n-2 ...
```

Space Complexity:

```text
O(n)
```

Because stack depth becomes `n`.

---

# Recursive Factorial

```cpp
int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}
```

Time Complexity:

```text
O(n)
```

Space Complexity:

```text
O(n)
```

Due to recursion stack.

---

# Iterative vs Recursive Space

---

## Recursive Version

```cpp
int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}
```

Space:

```text
O(n)
```

---

## Iterative Version

```cpp
int fact(int n) {
    int ans = 1;

    for(int i = 1; i <= n; i++) {
        ans *= i;
    }

    return ans;
}
```

Space:

```text
O(1)
```

---

# Stack Overflow

If recursion depth becomes too large:

```text
Stack Overflow Error
```

Occurs because stack memory is limited.

---

# Tail Recursion

Recursive call is the last operation.

Example:

```cpp
void fun(int n) {
    if(n == 0) return;
    fun(n - 1);
}
```

Some compilers optimize tail recursion.

This optimization is called:

```text
Tail Call Optimization (TCO)
```

---

# Space Complexity of STL Containers

| STL Container | Space Complexity |
|---|---|
| vector | O(n) |
| stack | O(n) |
| queue | O(n) |
| deque | O(n) |
| set | O(n) |
| map | O(n) |
| unordered_map | O(n) |
| priority_queue | O(n) |

---

# Space Complexity of Graphs

---

## Adjacency Matrix

```cpp
int graph[n][n];
```

Space:

```text
O(n²)
```

---

## Adjacency List

```cpp
vector<int> graph[n];
```

Space:

```text
O(V + E)
```

Better for sparse graphs.

---

# Space Complexity of Trees

---

## Binary Tree Nodes

If tree has `n` nodes:

```text
O(n)
```

---

## Recursive DFS

Space depends on tree height.

Balanced Tree:

```text
O(log n)
```

Skewed Tree:

```text
O(n)
```

---

# In-Place Algorithms

Algorithms using very little extra memory.

Usually:

```text
O(1) auxiliary space
```

Examples:

- Bubble Sort
- Selection Sort
- Two Pointer techniques

---

# Out-of-Place Algorithms

Require extra memory.

Example:

- Merge Sort

Needs temporary arrays.

Space:

```text
O(n)
```

---

# Dynamic Memory Allocation

Memory allocated during runtime.

Example:

```cpp
int* arr = new int[n];
```

Space:

```text
O(n)
```

---

# Memory Leaks

Occurs when dynamically allocated memory is not freed.

Example:

```cpp
int* arr = new int[n];
```

Without:

```cpp
delete[] arr;
```

Memory remains occupied.

---

# Space Complexity in Divide and Conquer

---

## Merge Sort

Temporary arrays + recursion stack.

Total Auxiliary Space:

```text
O(n)
```

---

## Quick Sort

Average recursion depth:

```text
O(log n)
```

Worst case recursion depth:

```text
O(n)
```

---

# Space Complexity of BFS and DFS

---

## BFS

Uses queue.

Worst case:

```text
O(V)
```

---

## DFS Recursive

Uses recursion stack.

Worst case:

```text
O(V)
```

---

# Space Optimization Techniques

---

## 1. Use Iteration Instead of Recursion

Reduces stack memory.

---

## 2. Use Bit Manipulation

Store multiple boolean values compactly.

---

## 3. Sliding Window Technique

Avoids storing unnecessary subarrays.

---

## 4. Space Optimized DP

Convert:

```text
O(n²) → O(n)
```

Using previous state optimization.

---

# Time vs Space Tradeoff

Sometimes we use more memory to reduce time.

Examples:

- Hash maps
- Prefix sums
- Dynamic Programming

Tradeoff:

```text
More Space → Less Time
```

---

# Complexity of Popular Algorithms

| Algorithm | Auxiliary Space |
|---|---|
| Linear Search | O(1) |
| Binary Search Iterative | O(1) |
| Binary Search Recursive | O(log n) |
| Bubble Sort | O(1) |
| Selection Sort | O(1) |
| Insertion Sort | O(1) |
| Merge Sort | O(n) |
| Quick Sort | O(log n) average |
| BFS | O(V) |
| DFS Recursive | O(V) |
| Heap Sort | O(1) |

---

# Important Competitive Programming Notes

Memory limits are usually:

```text
256 MB
512 MB
1024 MB
```

Approximate memory:

| Data Type | Size |
|---|---|
| int | 4 bytes |
| long long | 8 bytes |
| char | 1 byte |
| bool | 1 byte |
| double | 8 bytes |

---

# Array Memory Formula

For integer array:

```text
Memory = n × 4 bytes
```

Example:

```text
10^6 integers ≈ 4 MB
```

---

# Matrix Memory Formula

For integer matrix:

```text
Memory = n² × 4 bytes
```

Example:

```text
1000 × 1000 matrix ≈ 4 MB
```

---

# Common Mistakes

---

## Mistake 1

Ignoring recursion stack space.

---

## Mistake 2

Confusing total space with auxiliary space.

---

## Mistake 3

Using huge arrays globally without checking limits.

---

## Mistake 4

Using recursion for very deep calls.

---

# Space Complexity Ranking

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²)
```

---

# Quick Revision Sheet

| Pattern | Space Complexity |
|---|---|
| Variables only | O(1) |
| Extra array | O(n) |
| Matrix | O(n²) |
| Recursive depth n | O(n) |
| Balanced recursion tree | O(log n) |
| Hash map storage | O(n) |

---

# Real Interview Insights

Interviewers expect:

- Time optimization
- Space optimization
- In-place solution discussion
- Recursive stack understanding
- Memory-efficient coding

---

# Golden Rules for DSA

1. Prefer O(1) auxiliary space when possible
2. Watch recursion depth carefully
3. Use iterative solutions for large inputs
4. Optimize DP memory
5. Understand stack vs heap memory

---

# Final Summary

Space Complexity measures:

- Memory growth
- Scalability
- Feasibility under memory limits

Most important concepts:

```text
O(1)
O(log n)
O(n)
O(n²)
Auxiliary Space
Recursion Stack
```

These concepts are heavily used in:

- DSA interviews
- Competitive programming
- System optimization
- Real-world software engineering