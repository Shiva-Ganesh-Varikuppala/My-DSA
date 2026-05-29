# Trees Complete Notes for DSA

---

## 1. Introduction to Trees

### What is a Tree
A **tree** is a hierarchical data structure consisting of nodes connected by edges. It is a collection of elements (nodes) where each node may have zero or more child nodes, and there is one special node called the **root**.

### Real World Examples
- File system directories
- Organization charts
- Family trees
- XML/HTML DOM structure
- Decision trees in AI

### Why Trees are Used
- Represent hierarchical data naturally
- Efficient searching, insertion, deletion (e.g., BST)
- Used in compilers, databases, networking
- Facilitate recursive algorithms due to their recursive structure

### Recursive Nature of Trees
Each subtree of a tree is itself a tree, enabling recursive definitions and algorithms:
```
Tree:
  - Root node
  - Zero or more subtrees (children), each is a tree
```

---

## 2. Terminology

| Term             | Definition                                                                                  |
|------------------|---------------------------------------------------------------------------------------------|
| **Node**         | Basic unit of a tree containing data and links to children                                 |
| **Edge**         | Connection between two nodes                                                               |
| **Root**         | The topmost node with no parent                                                           |
| **Parent**       | Node directly above a given node                                                          |
| **Child**        | Node directly below a given node                                                          |
| **Sibling**      | Nodes sharing the same parent                                                              |
| **Ancestor**     | All nodes on the path from root to the node (excluding the node itself)                     |
| **Descendant**   | Nodes reachable by traversing downwards from a node                                        |
| **Leaf Node**    | Node with no children                                                                      |
| **Internal Node**| Node with at least one child                                                               |
| **Degree of Node**| Number of children a node has                                                             |
| **Degree of Tree**| Maximum degree among all nodes                                                            |
| **Path**         | Sequence of nodes connected by edges                                                      |
| **Path Length**  | Number of edges in a path                                                                  |
| **Level**        | Distance from the root node (root at level 0)                                             |
| **Depth**        | Level of a node                                                                           |
| **Height of Node**| Number of edges on longest path from node to leaf                                        |
| **Height of Tree**| Height of root node                                                                       |
| **Subtree**      | Tree formed by a node and its descendants                                                 |
| **Forest**       | Collection of disjoint trees                                                             |
| **Ordered Tree** | Children of a node have a fixed order                                                    |
| **Unordered Tree**| Children have no specific order                                                         |

---

## 3. Types of Trees

- **General Tree**: Any tree with arbitrary number of children per node
- **Binary Tree**: Each node has at most two children (left and right)
- **N-ary Tree**: Each node can have up to N children
- **Full Binary Tree**: Every node has 0 or 2 children
- **Perfect Binary Tree**: Full binary tree where all leaves are at same depth
- **Complete Binary Tree**: All levels filled except possibly last, which is filled left to right
- **Balanced Binary Tree**: Height difference between left and right subtrees ≤ 1 for every node
- **Degenerate Tree**: Each parent has only one child (like a linked list)
- **Skewed Tree**: All nodes have only left or only right child

---

## 4. Binary Tree Fundamentals

### Structure Definition in C++
```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};
```

### Binary Tree Properties
- Maximum nodes at level `l` = 2^l
- Maximum nodes in tree of height `h` = 2^(h+1) - 1
- Minimum height for `n` nodes = `⌈log2(n+1) -1⌉`

---

## 5. Tree Representations

| Representation           | Description                                   | When to Use                          |
|-------------------------|-----------------------------------------------|------------------------------------|
| **Linked Representation**| Nodes with pointers to children               | Dynamic trees, varying children    |
| **Array Representation** | Store nodes in array using index relations    | Complete binary trees, heaps       |
| **Parent Array**         | Array storing parent of each node              | Quick parent lookup, static trees  |
| **Adjacency List**       | Graph representation of tree                   | General trees, graph algorithms    |

---

## 6. Binary Tree Traversals

### DFS Overview
Depth First Search explores as far as possible along each branch before backtracking.

### Traversal Types
- **Preorder:** Root → Left → Right
- **Inorder:** Left → Root → Right
- **Postorder:** Left → Right → Root

### Recursive C++ Snippets
```cpp
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

### Iterative Concepts
- Use stack to simulate recursion
- For inorder, use controlled traversal to leftmost node

### Euler Tour Concept
Visits each edge exactly twice, useful for solving subtree queries.

### Traversal Comparison Table

| Traversal | Root Visited | Left Subtree | Right Subtree | Usage                         |
|-----------|--------------|--------------|---------------|-------------------------------|
| Preorder  | Before       | Left         | Right         | Copy tree, prefix expression  |
| Inorder   | Between      | Left         | Right         | Sorted output of BST           |
| Postorder | After        | Left         | Right         | Delete tree, postfix expression|

---

## 7. Breadth First Search

### Level Order Traversal
Visit nodes level by level from root down.

### Queue Based Approach
- Enqueue root
- While queue not empty:
  - Dequeue node, process it
  - Enqueue children

### Variants
- **Reverse Level Order:** Process levels from bottom to top
- **Zigzag Traversal:** Alternate direction each level
- **Vertical Traversal:** Nodes grouped by horizontal distance
- **Boundary Traversal:** Nodes on boundary in order
- **Views:**
  - Top view: Nodes visible from above
  - Bottom view: Nodes visible from below
  - Left view: Leftmost nodes at each level
  - Right view: Rightmost nodes at each level
- **Diagonal Traversal:** Nodes grouped by diagonals

---

## 8. Important Binary Tree Problems

- **Count nodes:** Traverse and count all nodes
- **Count leaf nodes:** Count nodes with no children
- **Count internal nodes:** Nodes with at least one child
- **Height of tree:** Max depth of any node
- **Diameter of tree:** Longest path between any two nodes
- **Balanced tree check:** Height difference ≤ 1 for all nodes
- **Maximum path sum:** Max sum of values along any path
- **Same tree check:** Structural and value equality
- **Symmetric tree:** Mirror image around center
- **Mirror tree:** Swap left and right children recursively
- **Lowest common ancestor (LCA):** Deepest common ancestor of two nodes
- **Path from root to node:** Store path during traversal
- **Root to leaf paths:** Print all paths
- **Children sum property:** Node value equals sum of children values
- **Sum tree:** Each node value equals sum of subtree nodes
- **Serialization and deserialization:** Convert tree to string and back

---

## 9. Binary Search Tree (BST)

### Definition
Binary tree where left subtree has smaller values, right subtree larger.

### BST Property
For every node:
```
left->data < node->data < right->data
```

### Operations
- **Search:** Traverse left/right based on comparison
- **Insert:** Insert at appropriate leaf position
- **Delete:** Remove node maintaining BST property
- **Successor:** Next higher value node
- **Predecessor:** Next lower value node
- **Min and Max:** Leftmost and rightmost nodes

### Complexity
- Average: O(log n)
- Worst: O(n) (skewed)

### Validation of BST
Check recursively if all nodes satisfy BST property with value ranges.

### Kth Smallest/Largest
Inorder traversal gives sorted order; pick kth element.

### LCA in BST
Traverse from root, move left/right based on node values.

### Recover BST
Fix swapped nodes by inorder traversal.

---

## 10. Balanced Search Trees

### Why Balancing is Required
To maintain O(log n) operations by keeping tree height minimal.

### AVL Tree
- Self-balancing BST
- Balance factor = height(left) - height(right)
- Rotations:
  - **LL Rotation:** Right rotate
  - **RR Rotation:** Left rotate
  - **LR Rotation:** Left rotate then right rotate
  - **RL Rotation:** Right rotate then left rotate
- Complexity: O(log n) for all operations

### Red Black Tree
- Binary tree with color property (Red/Black)
- Properties:
  - Root is black
  - Red nodes have black children
  - Every path has same black nodes count
- Rotations and recoloring maintain balance
- Complexity: O(log n)

### Comparison AVL vs Red Black
| Aspect           | AVL Tree         | Red Black Tree   |
|------------------|------------------|------------------|
| Balance          | Strict           | Less strict      |
| Rotations        | More frequent    | Less frequent    |
| Lookup           | Faster           | Slower           |
| Insert/Delete    | Slower           | Faster           |

---

## 11. Heap Trees

### Heap Introduction
Complete binary tree satisfying heap property.

### Types
- **Min Heap:** Parent ≤ children
- **Max Heap:** Parent ≥ children

### Array Representation
For node at index `i`:
- Left child: `2*i + 1`
- Right child: `2*i + 2`
- Parent: `(i-1)/2`

### Operations
- **Heapify:** Fix heap property from node downwards
- **Build Heap:** Heapify all non-leaf nodes bottom-up
- **Insert:** Add at end, bubble up
- **Delete:** Remove root, replace with last, heapify down

### Priority Queue Relation
Heap is underlying data structure for priority queues.

### Heap Sort
Build max heap, repeatedly extract max and heapify.

### Complexity Table

| Operation | Time Complexity |
|-----------|-----------------|
| Build Heap| O(n)            |
| Insert    | O(log n)        |
| Delete    | O(log n)        |
| Heap Sort | O(n log n)      |

---

## 12. Trie

### Introduction
Tree-like structure to store strings efficiently.

### Structure
Each node represents a character, edges represent transitions.

### Operations
- **Insert:** Add characters as nodes
- **Search:** Traverse nodes matching characters
- **Prefix Search:** Check if prefix exists

### Applications
- Autocomplete
- Spell checking
- IP routing

### Complexity
- Insert/Search: O(length of word)

---

## 13. Segment Tree

### Why Segment Trees Exist
Efficiently answer range queries and updates on arrays.

### Range Query Problems
Sum, min, max, gcd in a range.

### Construction
Build tree bottom-up from array segments.

### Query
Combine results from nodes covering query range.

### Update
Update value and adjust ancestors.

### Lazy Propagation
Delay updates to avoid repeated computations.

### Complexity
- Build: O(n)
- Query/Update: O(log n)

---

## 14. Fenwick Tree (Binary Indexed Tree)

### Concept
Data structure for prefix sums and updates.

### Update
Add value to an element and update ancestors.

### Prefix Sum
Sum from start to given index.

### Complexity
Both operations in O(log n).

### Fenwick vs Segment Tree
Fenwick is simpler and uses less memory but supports fewer query types.

---

## 15. Advanced Trees

- **B Tree:** Balanced tree for databases, multiple keys per node
- **B+ Tree:** Variant of B tree with linked leaves
- **2-3 Tree:** Nodes have 2 or 3 children
- **Splay Tree:** Self-adjusting BST with splaying
- **Treap:** BST + heap priority
- **Cartesian Tree:** Heap ordered by one key, BST by another
- **KD Tree:** Space partitioning for k-dimensional data
- **Interval Tree:** Stores intervals for overlap queries
- **Suffix Tree:** Represents suffixes of a string for pattern matching

---

## 16. Tree Dynamic Programming

### Introduction
Use DP to solve optimization problems on trees.

### Rerooting Technique
Compute result for all roots by rerooting.

### DP on Subtree
Store solutions for subtrees.

### DP on Paths
Solve problems involving paths between nodes.

### Typical Problems
- Diameter
- Maximum weighted independent set
- Counting paths

---

## 17. Generic Tree Algorithms

- **DFS on Trees:** Explore nodes recursively or with stack
- **BFS on Trees:** Level order traversal using queue
- **Tree Diameter:** Longest path between any two nodes
- **Tree Center:** Node(s) minimizing max distance to others
- **Tree Centroid:** Node splitting tree into balanced parts
- **Subtree Size:** Count nodes in subtree
- **Euler Tour Technique:** Linearizes tree for queries
- **Flattening Trees:** Convert tree to array for segment tree use

---

## 18. Binary Lifting

### Concept
Preprocessing ancestors at powers of two for fast queries.

### Ancestor Queries
Find kth ancestor quickly.

### LCA Using Binary Lifting
Find Lowest Common Ancestor in O(log n).

### Complexity
Preprocessing: O(n log n), Queries: O(log n)

---

## 19. Heavy Light Decomposition

### Motivation
Decompose tree to handle path queries efficiently.

### Heavy and Light Edges
Heavy edge: leads to largest subtree; others are light.

### Query Decomposition
Split path into heavy paths.

### Usage with Segment Trees
Apply segment tree on heavy paths for updates and queries.

---

## 20. Important Competitive Programming Concepts

- **Entry and Exit Time:** DFS timestamps to represent subtree
- **In-time and Out-time:** Used for ancestor checks
- **Ancestor Checks:** Using time intervals
- **DSU on Trees Overview:** Union-Find technique on tree paths
- **Mo's Algorithm on Trees:** Offline queries optimization

---

## 21. Trees in Graph Theory

- **Tree as a Graph:** Connected acyclic graph
- **Spanning Tree:** Tree connecting all graph nodes
- **Minimum Spanning Tree Overview:** Tree with minimum edge weight sum
- **Rooted vs Unrooted Trees:** Rooted has designated root, unrooted does not

---

## 22. Complexity Cheat Sheet

| Structure           | Search | Insert | Delete | Space      |
|---------------------|--------|--------|--------|------------|
| Binary Tree         | O(n)   | O(n)   | O(n)   | O(n)       |
| Binary Search Tree  | O(log n) avg, O(n) worst | O(log n) avg | O(log n) avg | O(n) |
| AVL Tree            | O(log n) | O(log n) | O(log n) | O(n)       |
| Red Black Tree      | O(log n) | O(log n) | O(log n) | O(n)       |
| Heap                | O(n)   | O(log n) | O(log n) | O(n)       |
| Trie                | O(k)   | O(k)   | O(k)   | O(ALPHABET * k * n) |
| Segment Tree        | O(log n) | O(log n) | O(log n) | O(4n)      |
| Fenwick Tree        | O(log n) | O(log n) | N/A    | O(n)       |

---

## 23. Interview Preparation Section

### Most Asked Tree Questions
- Validate BST
- Find LCA
- Serialize/Deserialize tree
- Diameter of tree
- Balanced tree check
- Tree traversal variants
- Construct tree from traversals

### Common Mistakes

- Confusing height and depth
- Not handling null nodes in recursion
- Misunderstanding tree properties
- Inefficient traversal implementations

### Problem Solving Strategy
- Understand problem constraints
- Choose appropriate tree type
- Use recursion with base cases
- Use auxiliary data structures if needed
- Optimize with DP or advanced techniques

---

## 24. Revision Sheet

| Topic                   | Key Points                                         |
|-------------------------|---------------------------------------------------|
| Tree Basics             | Nodes, edges, root, parent, child                  |
| Binary Trees            | Max nodes, height, traversal types                 |
| BST                     | Property, search, insert, delete                    |
| Balanced Trees          | AVL, Red Black, rotations                           |
| Heap                    | Min/Max heap, heapify, heap sort                    |
| Trie                    | Prefix tree, insert, search                         |
| Segment Tree            | Range queries, lazy propagation                     |
| Fenwick Tree            | Prefix sums, updates                                |
| Advanced Trees          | B Tree, Splay, Treap                                |
| DP on Trees             | Subtree and path DP                                 |
| Binary Lifting          | Ancestor queries, LCA                               |
| Heavy Light Decomposition| Path queries, segment tree integration              |

---

*End of Trees Complete Notes for DSA*
