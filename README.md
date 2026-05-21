# DSA (Data Structures & Algorithms) Repository

A comprehensive collection of **Data Structures** and **Algorithms** implementations in **C++** and **Python**, organized by topic for easy learning and reference.

---

## 📁 Folder Structure

### Core Data Structures

- **Arrays/** - Array operations (search, sorting, rotation, etc.)
- **LinkedLists/** - Singly/doubly linked lists, list manipulation
- **Stack/** - Stack implementations and problems
- **Queues/** - Queue types (simple, circular, double-ended)
- **Trees/** - Binary trees, BSTs, tree traversals
- **Graphs/** - Graph representations (adjacency matrix/list), algorithms

### Algorithm Categories

- **Searching/** - Linear search, binary search, interpolation search
- **Sorting/** - Comparison-based and non-comparison based sorting algorithms
- **Backtracking Algos/** - N-Queens, Rat in maze, Sudoku solver, Word search
- **DP_Algos/** - Dynamic programming (knapsack, LCS, edit distance, etc.)
- **GreedyAlgos/** - Activity selection, Dijkstra's, Prim's, Kruskal's, Huffman coding
- **Recursion/** - Recursive problem solving techniques
- **String Algos/** - String manipulation and pattern matching

### Pattern-Based Learning

- **Patterns/** - Organized by pattern types:
  - Binary Search
  - Sliding Window
  - Two Pointers
  - Prefix Sum
  - Difference Array
  - Merge Intervals
  - Monotonic Stack
  - And more...

### Specialized Topics

- **BitManipulationAlgos/** - Bit-level operations and tricks
- **ComputationalGeometryAlgos/** - Geometric algorithms
- **HeapAlgos/** - Heap operations and priority queue problems
- **MathematicalAlgos/** - Number theory, modular arithmetic
- **RangeQueryAlgos/** - Range queries, segment trees

---

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: `clang++` (macOS) or `g++` (Linux/Windows)
- **Python 3.6+** (for Python implementations)
- Any text editor or IDE (VS Code, CLion, etc.)

### Compiling C++ Files

#### Single File

```bash
cd /path/to/algorithm
clang++ -std=c++17 filename.cpp -o output_name
./output_name
```

#### Example: Graph Algorithm

```bash
cd /Users/vsg/Documents/DSA/Graphs
clang++ -std=c++17 graph.cpp -o graph
./graph
```

#### Using Makefile (if available)

```bash
make
make run
```

### Running Python Files

```bash
python3 filename.py
```

---

## 📚 Algorithm Index

### Arrays (`Arrays/`)

- Binary Search
- Linear Search
- Count Frequency
- Find Max/Min
- First & Last Occurrence
- Left Rotate (by K)
- Reverse Array
- Remove Duplicates
- Move Zeroes
- isSorted Check

**Example:**

```bash
cd Arrays
clang++ -std=c++17 BinarySearch.cpp -o bs
./bs
```

### Graphs (`Graphs/`)

- Graph Representation (Adjacency Matrix & List)
- DFS/BFS (if implemented)
- Shortest Path Algorithms

**Example:**

```bash
cd Graphs
clang++ -std=c++17 graph.cpp -o graph
./graph
```

### Linked Lists (`LinkedLists/`)

- Singly Linked List
- Doubly Linked List
- Reverse Linked List
- Check Palindrome
- Remove Nth Node
- Sort Linked List

### Dynamic Programming (`DP_Algos/`)

- 0/1 Knapsack
- Unbounded Knapsack
- Coin Change
- Longest Common Subsequence
- Longest Increasing Subsequence
- Edit Distance
- DP on Trees

### Backtracking (`Backtracking Algos/`)

- N-Queens Problem
- Rat in Maze
- Sudoku Solver
- Word Search

### Greedy Algorithms (`GreedyAlgos/`)

- Activity Selection
- Dijkstra's Algorithm
- Prim's Algorithm
- Kruskal's Algorithm
- Fractional Knapsack
- Huffman Coding

### Sorting (`Sorting/`)

Multiple sorting algorithms with various complexities

### Pattern-Based (`Patterns/`)

Learn algorithms organized by technique:

- Sliding Window
- Two Pointers
- Binary Search Variants
- Prefix/Suffix Techniques
- Monotonic Stack/Queue

---

## 💡 How to Use This Repository

### For Learning

1. **Pick a topic** from the folder structure
2. **Read the comments/theory** in the C++ files (most include detailed explanations)
3. **Compile and run** the code to see it in action
4. **Modify and experiment** with different inputs
5. **Compare implementations** (different approaches for the same problem)

### For Reference

- Use `Algorithm_library.txt` for quick lookup
- Check `daily.txt` for daily problem tracking

### For Practice

1. Start with simpler algorithms (Arrays, Searching)
2. Move to intermediate (Sorting, Basic Trees)
3. Progress to advanced (DP, Graphs, Backtracking)

---

## 📝 Code Structure

Most files follow this pattern:

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
*================* THEORY *================*
Detailed explanation of the algorithm/data structure
- Key concepts
- Complexity analysis
- Use cases
*/

int main() {
    // Implementation
    // Output
    return 0;
}
```

---

## 🔧 Build & Run Examples

### Arrays - Binary Search

```bash
cd Arrays
clang++ -std=c++17 BinarySearch.cpp -o bs
./bs
```

### Graphs - Graph Representation

```bash
cd Graphs
clang++ -std=c++17 graph.cpp -o graph
./graph
# Output: Adjacency matrix and adjacency list
# 0 1 1 0
# 1 0 0 1
# 1 0 0 1
# 0 1 1 0
#
# 0 : 1 2
# 1 : 0 3
# 2 : 0 3
# 3 : 1 2
```

### Linked Lists

```bash
cd LinkedLists
clang++ -std=c++17 Singly_linkedlist.cpp -o ll
./ll
```

---

## 🎯 Complexity Reference

| Algorithm     | Time          | Space    | Use Case                   |
| ------------- | ------------- | -------- | -------------------------- |
| Linear Search | O(n)          | O(1)     | Unsorted data              |
| Binary Search | O(log n)      | O(1)     | Sorted data                |
| Bubble Sort   | O(n²)         | O(1)     | Small datasets             |
| Merge Sort    | O(n log n)    | O(n)     | Large datasets             |
| Quick Sort    | O(n log n)\*  | O(log n) | Average case               |
| DFS           | O(V+E)        | O(V)     | Graph traversal            |
| BFS           | O(V+E)        | O(V)     | Shortest path (unweighted) |
| Dijkstra      | O((V+E)log V) | O(V)     | Shortest path (weighted)   |
| DP Knapsack   | O(nW)         | O(nW)    | Optimization               |

\*Average case; worst case O(n²)

---

## 📖 Learning Path (Recommended)

### Beginner

1. Arrays & Searching
2. Basic Sorting
3. Strings

### Intermediate

1. Linked Lists
2. Stacks & Queues
3. Trees & Tree Traversals
4. Basic Graphs

### Advanced

1. Dynamic Programming
2. Advanced Graph Algorithms
3. Backtracking
4. Greedy Algorithms
5. Bit Manipulation

---

## 🐛 Debugging Tips

### Compilation Errors

- Ensure C++ standard is compatible: `clang++ -std=c++17`
- Check #include paths for all dependencies
- Verify syntax and braces

### Runtime Issues

- Add debug output with `cout << variable << endl;`
- Use smaller test cases first
- Check edge cases (empty arrays, single elements, etc.)

### Common Issues

- **Vector index out of bounds**: Verify loop conditions
- **Segmentation fault**: Check pointer/reference validity
- **Logic errors**: Trace through algorithm with sample input

---

## 📞 Contributing

To add new algorithms or improvements:

1. Follow the existing code structure and commenting style
2. Include theory/explanation comments
3. Add meaningful variable names
4. Test with multiple cases
5. Update this README if adding new categories

---

## 📌 Quick Commands Reference

```bash
# Navigate to DSA folder
cd /Users/vsg/Documents/DSA

# List all categories
ls -la

# Compile a C++ file
clang++ -std=c++17 filename.cpp -o output_name

# Run compiled program
./output_name

# Run Python file
python3 filename.py

# View file contents
cat filename.cpp

# Search for specific algorithm
grep -r "algorithm_name" .
```

---

## 📄 File Information

- **Repository**: My-DSA
- **Owner**: shiva676466
- **Language**: C++ (primary), Python (secondary)
- **Last Updated**: May 2026

---

## 🎓 Educational Purpose

This repository is designed for:

- ✅ Learning data structures and algorithms
- ✅ Interview preparation
- ✅ Competitive programming
- ✅ Algorithm reference
- ✅ Code optimization practice

---

## 📞 Notes

- Most implementations use **0-indexed arrays**
- Comments explain **time and space complexity**
- Code includes **practical examples** with sample outputs
- **Edge cases** are considered in implementations

---

## Happy Learning! 🚀

Feel free to explore, modify, and use these algorithms as a reference for your learning journey.
