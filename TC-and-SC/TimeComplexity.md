

# Time Complexity Notes

## What is Time Complexity?

Time Complexity measures how the running time of an algorithm grows as the input size increases.

It does NOT measure actual time in seconds.

It measures:

- Number of operations
- Growth rate
- Efficiency of algorithm

---

# Why Do We Study Time Complexity?

Two programs may solve the same problem.

Example:

- One runs in 1 second for 1000 inputs
- Another runs in 1 hour for 1000 inputs

Time Complexity helps us:

- Compare algorithms
- Write optimized code
- Predict performance for large inputs
- Avoid TLE (Time Limit Exceeded)

---

# Input Size

Usually represented by:

```text
n
```

Examples:

- Array size
- Number of nodes in graph
- Length of string
- Number of test cases

---

# Frequency Count Method

We count how many times an operation executes.

Example:

```cpp
for(int i = 0; i < n; i++) {
    cout << i;
}
```

`cout` runs:

```text
n times
```

So complexity:

```text
O(n)
```

---

# What is Big O Notation?

Big O notation represents the upper bound (worst-case growth).

Example:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
```

---

# Rules for Calculating Time Complexity

---

## 1. Ignore Constants
We ignore constants in Time and space complexities because complexity analysis focuses on: Growth Rate not exact execution time 
or exact memory.

```cpp
for(int i = 0; i < 2*n; i++) {}
```

Complexity:

```text
O(n)
```

Because constants are ignored.

---

## 2. Drop Lower Order Terms

```text
n² + n + 10
```

Complexity:

```text
O(n²)
```

Because dominant term matters.

---

## 3. Different Inputs Use Different Variables

```cpp
for(int i = 0; i < n; i++) {}
for(int j = 0; j < m; j++) {}
```

Complexity:

```text
O(n + m)
```

---

# Common Time Complexities

| Complexity | Name | Example |
|---|---|---|
| O(1) | Constant | Array access |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Traversing array |
| O(n log n) | Linearithmic | Merge Sort |
| O(n²) | Quadratic | Nested loops |
| O(n³) | Cubic | Triple nested loops |
| O(2ⁿ) | Exponential | Recursive subsets |
| O(n!) | Factorial | Permutations |

---

# O(1) — Constant Time

Operations execute fixed number of times.

```cpp
int x = arr[5];
```

No matter input size.

---

# O(log n) — Logarithmic Time

Input reduces by half every step.

Example:

```cpp
while(n > 1) {
    n /= 2;
}
```

Examples:

- Binary Search
- Segment Tree Queries
- Heap Operations

---

# Binary Search Complexity

```text
T(n) = log₂ n
```

Each step halves search space.

---

# O(n) — Linear Time

Operations proportional to input size.

```cpp
for(int i = 0; i < n; i++) {}
```

---

# O(n²) — Quadratic Time

Usually nested loops.

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {

    }
}
```

Complexity:

```text
n × n = n²
```

---

# O(n log n)

Very important complexity.

Efficient sorting algorithms:

- Merge Sort
- Heap Sort
- Quick Sort (average case)

---

# O(2ⁿ) — Exponential

Every recursive call branches into two.

Example:

```cpp
fib(n) = fib(n-1) + fib(n-2)
```

Very slow for large inputs.

---

# O(n!) — Factorial

Example:

- Generating all permutations

```text
n × (n-1) × (n-2) ...
```

Extremely expensive.

---

# Best, Average, Worst Case

## Best Case

Minimum operations.

## Average Case

Expected operations.

## Worst Case

Maximum operations.

Most interview problems use:

```text
Worst Case Complexity
```

We usually focus on worst-case time complexity because it gives the maximum time an alogrithm can
take for any input size of n.

---

# Examples of Cases

## Linear Search

### Best Case

Element at first position.

```text
O(1)
```

### Worst Case

Element at last position.

```text
O(n)
```

---

# Nested Loops Analysis

---

## Independent Loops

```cpp
for(int i = 0; i < n; i++) {}
for(int j = 0; j < n; j++) {}
```

Complexity:

```text
O(n + n) = O(n)
```

---

## Dependent Loops

```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {}
}
```

Complexity:

```text
O(n²)
```

---

# Loop Complexity Patterns

---

## Loop Dividing by 2

```cpp
for(int i = n; i > 1; i /= 2)
```

Complexity:

```text
O(log n)
```

---

## Loop Multiplying by 2

```cpp
for(int i = 1; i < n; i *= 2)
```

Complexity:

```text
O(log n)
```

---

## Square Root Complexity

```cpp
for(int i = 1; i * i <= n; i++)
```

Complexity:

```text
O(√n)
```

---

# Complexity of Recursion

---

## Simple Recursion

```cpp
void fun(int n) {
    if(n == 0) return;
    fun(n-1);
}
```

Complexity:

```text
O(n)
```

---

## Fibonacci Recursion

```cpp
fib(n-1) + fib(n-2)
```

Complexity:

```text
O(2ⁿ)
```

---

# Recurrence Relations

Used in divide and conquer.

---

## Merge Sort

```text
T(n) = 2T(n/2) + n
```

Complexity:

```text
O(n log n)
```

---

# Master Theorem

Used for recurrence relations.

General form:

```text
T(n) = aT(n/b) + f(n)
```

Where:

- `a` = number of recursive calls
- `b` = division factor
- `f(n)` = extra work

---

# Amortized Time Complexity

Average complexity over multiple operations.

Example:

- `push_back()` in vector

Single resize may cost O(n), but average:

```text
O(1)
```

---

# Space Complexity

Measures memory usage.

Includes:

- Variables
- Arrays
- Recursion stack
- Dynamic memory

---

# Auxiliary Space

Extra space used excluding input.

Example:

```cpp
int arr[n];
```

Input array is NOT auxiliary space.

---

# Time Complexity vs Space Complexity

Sometimes faster algorithms use more memory.

Example:

- Hashing
- Dynamic Programming

Tradeoff:

```text
Time ↔ Space
```

---

# Complexity of Popular Algorithms

| Algorithm | Time Complexity |
|---|---|
| Linear Search | O(n) |
| Binary Search | O(log n) |
| Bubble Sort | O(n²) |
| Selection Sort | O(n²) |
| Insertion Sort | O(n²) |
| Merge Sort | O(n log n) |
| Quick Sort (avg) | O(n log n) |
| Quick Sort (worst) | O(n²) |
| BFS | O(V + E) |
| DFS | O(V + E) |
| Dijkstra | O(E log V) |

---

# Complexity of STL Operations

| STL | Operation | Complexity |
|---|---|---|
| vector | push_back | O(1) amortized |
| vector | insert | O(n) |
| stack | push/pop | O(1) |
| queue | push/pop | O(1) |
| set | insert/find | O(log n) |
| unordered_set | insert/find | O(1) average |
| map | insert/find | O(log n) |
| unordered_map | insert/find | O(1) average |
| priority_queue | push/pop | O(log n) |

---

# Important Competitive Programming Limits

Approximate operations per second:

```text
10^8 operations ≈ 1 second
```

---

# Complexity Guide by Input Size

| Input Size | Expected Complexity |
|---|---|
| n ≤ 10 | O(n!) |
| n ≤ 20 | O(2ⁿ) |
| n ≤ 500 | O(n³) |
| n ≤ 10⁴ | O(n²) |
| n ≤ 10⁶ | O(n log n) or O(n) |
| n ≥ 10⁷ | O(log n) or O(1) |

---

# How to Analyze an Algorithm

Step-by-step:

1. Count loops
2. Count recursion calls
3. Ignore constants
4. Keep dominant term
5. Analyze worst case

---

# Common Mistakes

---

## Mistake 1

Thinking nested loops always mean O(n²)

Example:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {}
}
```

Still:

```text
O(n²)
```

But not exactly `n × n` iterations.

---

## Mistake 2

Ignoring recursion stack space.

---

## Mistake 3

Confusing average case and worst case.

---

# Big Omega Notation Ω

Represents lower bound.

Best-case complexity.

Example:

```text
Ω(1)
```

---

# Theta Notation Θ

Represents tight bound.

Example:

```text
Θ(n)
```

Means exact asymptotic growth.

---

# Asymptotic Analysis

Analysis of algorithm growth for very large inputs.

Main notations:

- Big O
- Big Omega
- Theta

---

# Real Interview Insights

Interviewers expect:

- Correct complexity analysis
- Optimized approach
- Tradeoff discussion
- Space optimization

---

# Golden Rules for DSA

1. Prefer O(log n) over O(n)
2. Prefer O(n log n) sorting
3. Avoid O(n²) for large constraints
4. Watch recursion depth
5. Optimize brute force gradually

---

# Complexity Ranking (Best to Worst)

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

---

# Quick Revision Sheet

| Pattern | Complexity |
|---|---|
| Single loop | O(n) |
| Nested loops | O(n²) |
| Halving loop | O(log n) |
| Divide & Conquer | O(n log n) |
| Two nested independent inputs | O(nm) |
| Recursion tree branching by 2 | O(2ⁿ) |

---

# Final Summary

Time Complexity helps determine:

- Scalability
- Efficiency
- Optimization quality
- Feasibility for constraints

Most important complexities to master:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
```

These appear in almost every DSA interview and competitive programming problem.