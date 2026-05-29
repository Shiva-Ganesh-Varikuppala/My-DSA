# Arrays Complete Notes for DSA

---

## 1. Introduction to Arrays

**Intuition:**  
An array is a collection of elements, typically of the same type, stored in contiguous memory locations. Arrays allow efficient access to elements using indices.

**Definition:**  
An array is a data structure that stores elements in a linear order, where each element can be accessed directly via its index.

**Example:**  
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

**Diagram:**

| Index | 0 | 1 | 2 | 3 | 4 |
|-------|---|---|---|---|---|
| Value | 1 | 2 | 3 | 4 | 5 |

---

## 2. Why Arrays Are Important

- **Fast access:** O(1) time to access elements by index.
- **Foundation:** Many complex data structures (lists, heaps, hash tables) are built on arrays.
- **Memory efficiency:** Contiguous allocation improves cache locality.
- **Simplicity:** Easy to understand and implement.

---

## 3. Array Terminology

| Term           | Explanation                                   |
|----------------|-----------------------------------------------|
| Element        | An individual item stored in the array.       |
| Index          | Position of an element, zero-based in C++.    |
| Length/Size    | Number of elements in the array.               |
| Capacity       | Maximum number of elements array can hold.    |
| Contiguous     | Memory locations are adjacent.                 |

---

## 4. Memory Representation

Arrays are stored in contiguous blocks of memory. For an array of type `T` with `n` elements, the memory addresses are:

```
Base_Address + i * sizeof(T)  for i = 0 to n-1
```

---

## 5. Static vs Dynamic Arrays

| Feature           | Static Array                      | Dynamic Array                     |
|-------------------|---------------------------------|----------------------------------|
| Size              | Fixed at compile time            | Can grow/shrink at runtime        |
| Memory Allocation | Stack or static memory           | Heap memory                      |
| Flexibility       | Not flexible                    | Flexible                        |
| Example           | `int arr[10];`                   | `vector<int> v;` (C++ STL)       |

---

## 6. Array Operations

### Access

- Access element by index: `arr[i]`
- Time Complexity: O(1)

### Traversal

- Visit each element sequentially.
- Example:
```cpp
for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```
- Time Complexity: O(n)

### Insertion

- Insert at end (if space available): O(1)
- Insert at arbitrary position: O(n) (shifting elements)
- Example:
```cpp
// Insert at position pos
for(int i = n; i > pos; i--) {
    arr[i] = arr[i-1];
}
arr[pos] = value;
n++;
```

### Deletion

- Delete element at position pos: O(n) (shifting elements)
- Example:
```cpp
for(int i = pos; i < n-1; i++) {
    arr[i] = arr[i+1];
}
n--;
```

### Searching

- Linear Search: O(n)
- Binary Search (sorted arrays): O(log n)

### Updating

- Update element at index i: O(1)
- Example:
```cpp
arr[i] = newValue;
```

---

## 7. Time Complexity Analysis

| Operation  | Time Complexity          |
|------------|-------------------------|
| Access     | O(1)                    |
| Search     | O(n)                    |
| Insertion  | O(n)                    |
| Deletion   | O(n)                    |
| Traversal  | O(n)                    |

---

## 8. Types of Arrays

### 1D Arrays

- Linear list of elements.
- Example: `int arr[5];`

### 2D Arrays

- Matrix-like structure.
- Example: `int arr[3][4];`

### Multi-dimensional Arrays

- Arrays with more than 2 dimensions.
- Example: `int arr[2][3][4];`

### Jagged Arrays

- Arrays of arrays where inner arrays can have different lengths.
- Not directly supported in C++ but can be implemented with pointers or vectors.

---

## 9. Array Traversal Techniques

- **Row-wise:** Traverse row by row in 2D arrays.
- **Column-wise:** Traverse column by column.
- **Spiral:** Traverse in spiral order.
- **Diagonal:** Traverse diagonals.
- **Zigzag:** Traverse rows alternatively left-to-right and right-to-left.

---

## 10. Linear Search

**Definition:** Sequentially check each element until the target is found or end is reached.

**Code:**
```cpp
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}
```

---

## 11. Binary Search

**Pre-requisite:** Array must be sorted.

### Iterative Binary Search

```cpp
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Recursive Binary Search

```cpp
int binarySearchRec(int arr[], int low, int high, int target) {
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return binarySearchRec(arr, mid+1, high, target);
    else return binarySearchRec(arr, low, mid-1, target);
}
```

### Lower Bound

- First position where `arr[i] >= target`.
- Useful in insertion and counting.

### Upper Bound

- First position where `arr[i] > target`.

### First Occurrence

- Binary search variant to find first occurrence of target.

### Last Occurrence

- Binary search variant to find last occurrence of target.

### Search Insert Position

- Find position to insert target to keep array sorted.

---

## 12. Prefix Sum

**Definition:** Array where each element at index `i` is the sum of elements from `0` to `i` of original array.

**Formula:**  
`prefix[i] = prefix[i-1] + arr[i]`

**Use:** Efficient range sum queries.

**Code:**
```cpp
vector<int> prefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + arr[i];
    return prefix;
}
```

---

## 13. Difference Array

**Definition:** Array that stores the difference between consecutive elements.

**Use:** Efficient range updates.

**Example:**
To add `val` to all elements in range `[l, r]`:
```cpp
diff[l] += val;
if(r+1 < n) diff[r+1] -= val;
```

---

## 14. Sliding Window Technique

**Intuition:** Maintain a window (subarray) and slide it over the array to solve problems like max sum subarray of size k, longest substring with unique chars, etc.

**Example:** Maximum sum of subarray of size k.

---

## 15. Two Pointer Technique

**Intuition:** Use two indices to scan the array; useful for problems like pair sums, removing duplicates, etc.

---

## 16. Kadane's Algorithm

**Problem:** Find maximum sum subarray.

**Idea:** Keep track of current max ending here and global max.

**Code:**
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
```

---

## 17. Majority Element Algorithms

- **Boyer-Moore Voting Algorithm:** Find element that appears more than n/2 times.
- **Hash Map Counting:** Count frequencies.

---

## 18. Dutch National Flag Algorithm

**Problem:** Sort an array of 0s, 1s, and 2s in linear time and constant space.

**Approach:** Maintain three pointers: low, mid, high.

---

## 19. Moore Voting Algorithm

**Purpose:** Find majority element in O(n) time and O(1) space.

---

## 20. Hashing with Arrays

- Use arrays as hash maps for small ranges.
- Example: Frequency arrays.

---

## 21. Coordinate Compression

- Map large values to smaller ranges preserving order.
- Useful for segment trees, Fenwick trees.

---

## 22. Sorting Fundamentals

| Algorithm       | Time Complexity (Avg) | Space Complexity | Stable | Notes                                  |
|-----------------|-----------------------|------------------|--------|----------------------------------------|
| Bubble Sort     | O(n²)                 | O(1)             | Yes    | Simple but inefficient                  |
| Selection Sort  | O(n²)                 | O(1)             | No     | Simple, selects min element each pass  |
| Insertion Sort  | O(n²)                 | O(1)             | Yes    | Efficient for nearly sorted data       |
| Merge Sort      | O(n log n)            | O(n)             | Yes    | Divide and conquer                      |
| Quick Sort      | O(n log n)            | O(log n)         | No     | Fastest in practice, pivot selection key |
| Heap Sort       | O(n log n)            | O(1)             | No     | Uses heap data structure                |
| Counting Sort   | O(n + k)              | O(k)             | Yes    | For integers in small range             |
| Radix Sort      | O(d*(n + k))          | O(n + k)         | Yes    | Sorts digits, stable                    |
| Bucket Sort     | O(n + k)              | O(n)             | Yes    | Distributes elements into buckets       |

---

## 23. Array Rotation Techniques

- Rotate array by `d` positions.
- Methods:
  - Using extra array (O(n) space)
  - Reversal Algorithm (in-place)
  - Juggling Algorithm

---

## 24. Matrix Fundamentals

- 2D array representation.
- Rows and columns.
- Row-major and column-major storage.

---

## 25. Matrix Traversals

### Row-wise

Traverse each row left to right.

### Column-wise

Traverse each column top to bottom.

### Spiral

Traverse matrix in spiral order.

### Diagonal

Traverse diagonals (primary and secondary).

### Zigzag

Traverse rows alternatively left-to-right and right-to-left.

---

## 26. Matrix Problems

### Transpose

Swap `matrix[i][j]` with `matrix[j][i]`.

### Rotate Matrix

Rotate matrix by 90 degrees (clockwise or anticlockwise).

### Set Matrix Zeroes

Set entire row and column to zero if an element is zero.

### Search in Sorted Matrix

Search element in matrix where rows and columns are sorted.

---

## 27. Subarray Concepts

- Contiguous segment of an array.
- Used in problems like max subarray sum.

---

## 28. Subsequence Concepts

- Sequence derived by deleting zero or more elements without changing order.
- Example: Longest Increasing Subsequence.

---

## 29. Maximum Subarray Problems

- Kadane's Algorithm.
- Variants with constraints.

---

## 30. Prefix/Suffix Techniques

- Prefix sums, suffix sums for range queries.
- Useful in optimization.

---

## 31. Monotonic Stack Applications on Arrays

- Stack that maintains elements in sorted order.
- Used in next greater/smaller element problems.

---

## 32. Monotonic Queue Applications

- Queue maintaining monotonic property.
- Used in sliding window maximum/minimum.

---

## 33. Sparse Table Overview

- Data structure for range minimum/maximum queries.
- Preprocessing O(n log n), query O(1).

---

## 34. Range Query Techniques

- Segment Trees.
- Fenwick Trees (Binary Indexed Trees).
- Sparse Tables.

---

## 35. Offline Query Concepts

- Process queries in batch after sorting or preprocessing.

---

## 36. Advanced Array Techniques

### Meet in the Middle

Split problem into two halves to reduce complexity.

### Sweep Line

Process events sorted by coordinate.

### Difference Constraints

Solve inequalities using graph or arrays.

---

## 37. Competitive Programming Patterns

- Sliding window.
- Two pointers.
- Binary search on answer.
- Prefix sums.
- Hashing.

---

## 38. Interview Patterns

- Array partitioning.
- Sorting and searching.
- Sliding window for substrings.
- Frequency counting.

---

## 39. Common Mistakes

- Off-by-one errors.
- Not checking array bounds.
- Using wrong data types.
- Forgetting to initialize arrays.

---

## 40. Complexity Cheat Sheet

| Operation          | Time Complexity          |
|--------------------|-------------------------|
| Access             | O(1)                    |
| Search (unsorted)  | O(n)                    |
| Search (sorted)    | O(log n)                |
| Insertion          | O(n)                    |
| Deletion           | O(n)                    |
| Sorting            | O(n log n)              |

---

## 41. Revision Sheet

| Topic                      | Key Points                                  |
|----------------------------|---------------------------------------------|
| Arrays                     | Contiguous memory, O(1) access              |
| Searching                  | Linear and binary search                     |
| Sorting                    | Various algorithms, stability, and complexity |
| Prefix sums                | Efficient range queries                       |
| Sliding window             | Fixed and variable window problems           |
| Kadane's Algorithm         | Max subarray sum                              |
| Majority Element           | Boyer-Moore Voting                            |
| Matrix Problems            | Traversals, rotations, zeroing                |
| Advanced Techniques        | Meet in the middle, sparse tables             |

---

**Interview Tips:**  
- Always clarify array size and indexing.  
- Check edge cases like empty arrays or single element arrays.  
- Optimize search and insertion operations.  
- Use prefix sums and difference arrays to optimize range queries.  
- Practice common patterns and algorithms.

---

This document covers arrays comprehensively from basics to advanced techniques, preparing you for both academic and competitive programming challenges.
