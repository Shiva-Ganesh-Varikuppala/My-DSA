# Breadth First Search (BFS)

# Introduction

Breadth First Search (BFS) is a graph traversal algorithm.

It visits nodes:

```text
Level by Level
```

instead of going deep.

---

# Basic Idea of BFS

BFS starts from a source node and explores:

1. First all immediate neighbors
2. Then neighbors of neighbors
3. Then next levels

This is why BFS is called:

```text
Level Order Traversal
```

---

# Real Life Analogy

Imagine throwing a stone into water.

The waves spread:

```text
layer by layer
```

Similarly BFS explores graph level-wise.

---

# Data Structure Used in BFS

BFS uses:

```text
Queue
```

because queue works on:

```text
FIFO (First In First Out)
```

---

# Important Components

## 1. Queue

Stores nodes to visit.

---

## 2. Visited Array

Prevents revisiting nodes.

Without visited array:

- infinite loop may occur
- repeated traversal may happen

---

# Example Graph

```text
        0
      /   \
     1     2
    / \     \
   3   4     5
```

---

# BFS Traversal Order

Starting from:

```text
0
```

Traversal becomes:

```text
0 1 2 3 4 5
```

Reason:

- First visit 0
- Then all neighbors of 0
- Then neighbors of 1 and 2

---

# Step-by-Step Dry Run

## Initial State

Queue:

```text
[0]
```

Visited:

```text
0 = true
```

---

## Step 1

Pop:

```text
0
```

Push neighbors:

```text
1 2
```

Queue:

```text
[1, 2]
```

---

## Step 2

Pop:

```text
1
```

Push neighbors:

```text
3 4
```

Queue:

```text
[2, 3, 4]
```

---

## Step 3

Pop:

```text
2
```

Push neighbor:

```text
5
```

Queue:

```text
[3, 4, 5]
```

Continue until queue becomes empty.

---

# BFS Algorithm

## Steps

1. Create queue
2. Mark source visited
3. Push source into queue
4. While queue not empty:
   - pop front node
   - print/process node
   - visit all unvisited neighbors
   - push neighbors into queue

---

# BFS Code (Adjacency List)

```cpp
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, int n){

    vector<bool> visited(n, false);

    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : graph[node]){

            if(!visited[neighbor]){

                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){

    int n = 6;

    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[1].push_back(4);
    graph[4].push_back(1);

    graph[2].push_back(5);
    graph[5].push_back(2);

    bfs(graph, 0, n);

    return 0;
}
```

---

# Output

```text
0 1 2 3 4 5
```

---

# BFS Complexity

## Time Complexity

genui{"math_block_widget_always_prefetch_v2":{"content":"O(V + E)"}}

Where:

- V = Vertices
- E = Edges

Reason:

- every node visited once
- every edge checked once

---

## Space Complexity

genui{"math_block_widget_always_prefetch_v2":{"content":"O(V)"}}

Used by:

- queue
- visited array

---

# Why BFS Gives Shortest Path?

In an unweighted graph:

BFS visits nodes:

```text
minimum distance first
```

So first time reaching a node always gives shortest path.

---

# BFS Applications

## 1. Shortest Path in Unweighted Graph

---

## 2. Level Order Traversal in Trees

---

## 3. GPS Navigation

---

## 4. Social Networking

Finding mutual friends.

---

## 5. Network Broadcasting

---

## 6. Web Crawlers

Google crawling pages.

---

# BFS Using Matrix vs List

| Representation   | Complexity |
| ---------------- | ---------- |
| Adjacency Matrix | O(V²)      |
| Adjacency List   | O(V + E)   |

Adjacency list is preferred.

---

# BFS Traversal Tree

BFS naturally creates:

```text
Shortest Path Tree
```

from source node.

---

# Common Mistakes

## 1. Forgetting Visited Array

May cause infinite traversal.

---

## 2. Marking Visited Late

Wrong:

```cpp
q.push(neighbor);
visited[neighbor] = true;
```

Better:

```cpp
visited[neighbor] = true;
q.push(neighbor);
```

Reason:

- avoids duplicate insertions.

---

## 3. Using Stack Instead of Queue

That becomes DFS.

---

## 4. Not Handling Disconnected Graph

Single BFS may not visit all nodes.

---

# BFS for Disconnected Graph

```cpp
for(int i = 0; i < n; i++){

    if(!visited[i]){
        bfs(graph, i, visited);
    }
}
```

---

# Detailed Comparison Between BFS and DFS Traversals

## Comprehensive Comparison Table

| Aspect                   | BFS (Breadth First Search)                    | DFS (Depth First Search)                          |
| ------------------------ | --------------------------------------------- | ------------------------------------------------- |
| **Data Structure**       | Queue (FIFO)                                  | Stack (LIFO) or Recursion                         |
| **Traversal Order**      | Level-wise (explores all neighbors first)     | Depth-wise (goes as deep as possible)             |
| **Exploration Pattern**  | Explores nodes layer by layer                 | Explores nodes along a single path until dead end |
| **Shortest Path**        | Guarantees shortest path in unweighted graphs | Does NOT guarantee shortest path                  |
| **Memory Usage**         | More (stores all nodes at current level)      | Less (stores only nodes in current path)          |
| **Time Complexity**      | O(V + E)                                      | O(V + E)                                          |
| **Space Complexity**     | O(V) - worst case all nodes in queue          | O(h) - where h is height of tree/depth            |
| **Optimal For**          | Shortest path, level-order traversal          | Topological sort, cycle detection, backtracking   |
| **Implementation**       | Iterative (using queue)                       | Recursive or Iterative (using stack)              |
| **Backtracking**         | Not naturally suited                          | Naturally suited                                  |
| **All Paths Finding**    | Not suitable                                  | Suitable                                          |
| **Cycle Detection**      | Yes                                           | Yes                                               |
| **Connected Components** | Yes                                           | Yes                                               |

---

## Visual Example: BFS vs DFS

### Graph Example

```text
        0
      /   \
     1     2
    / \     \
   3   4     5
```

### BFS Traversal

```text
Order of Exploration: 0 → 1 → 2 → 3 → 4 → 5

Queue state:
Step 1: [0] (visit 0, add neighbors)
Step 2: [1, 2] (visit 1, add neighbors)
Step 3: [2, 3, 4] (visit 2, add neighbors)
Step 4: [3, 4, 5] (visit 3, no new neighbors)
Step 5: [4, 5] (visit 4, no new neighbors)
Step 6: [5] (visit 5, no new neighbors)
```

### DFS Traversal

```text
Order of Exploration: 0 → 1 → 3 → 4 → 2 → 5

Stack state:
Step 1: [0] (visit 0, add neighbors)
Step 2: [1, 2] (visit 1, add neighbors - goes deep)
Step 3: [3, 4, 2] (visit 3, no more neighbors)
Step 4: [4, 2] (backtrack to 1, visit 4)
Step 5: [2] (backtrack to 0, visit 2)
Step 6: [5] (visit 5, no neighbors)
```

---

## Use Case Comparison

### When to Use BFS

1. **Finding Shortest Path** in unweighted graphs
2. **Level-order Traversal** in trees
3. **Social Network Analysis** (finding friends at distance k)
4. **GPS Navigation** and route planning
5. **Web Crawler** - exploring pages level by level
6. **Broadcasting** in networks
7. **Bipartite Graph Detection**
8. **Connected Components** in unweighted context

### When to Use DFS

1. **Topological Sorting** (for DAGs)
2. **Cycle Detection** in directed graphs
3. **Strongly Connected Components** (Kosaraju's/Tarjan's algorithm)
4. **Backtracking Problems** (N-Queens, Sudoku solver, permutations)
5. **Detecting All Paths** between two nodes
6. **Maze Solving** with backtracking
7. **Tree Traversals** (Preorder, Inorder, Postorder)
8. **Connected Components** counting

---

## Time & Space Complexity Analysis

### Time Complexity Breakdown

| Operation            | BFS          | DFS          |
| -------------------- | ------------ | ------------ |
| Visiting each vertex | O(V)         | O(V)         |
| Checking each edge   | O(E)         | O(E)         |
| **Total**            | **O(V + E)** | **O(V + E)** |

### Space Complexity Breakdown

| Scenario                 | BFS                      | DFS                      |
| ------------------------ | ------------------------ | ------------------------ |
| **Balanced Binary Tree** | O(n/2) = O(n) worst case | O(log n) average         |
| **Skewed Tree**          | O(1) best case           | O(n) worst case          |
| **Graph (Dense)**        | O(V)                     | O(V) for recursion stack |
| **Graph (Sparse)**       | O(V)                     | O(V) for recursion stack |

---

## Code Comparison

### BFS Implementation (Iterative)

```cpp
void bfs(vector<vector<int>> &graph, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### DFS Implementation (Recursive)

```cpp
void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}
```

---

## Key Differences Summary

| Point                | BFS                                       | DFS                                             |
| -------------------- | ----------------------------------------- | ----------------------------------------------- |
| **Core Concept**     | Explore all neighbors before going deeper | Go as deep as possible before backtracking      |
| **Guarantee**        | Shortest path in unweighted graphs        | Explores all paths, explores one path fully     |
| **Best For**         | Shortest path problems                    | Exploring all solutions, backtracking           |
| **Implementation**   | Easy to understand, iterative             | Can be recursive or iterative                   |
| **Typical Problems** | Shortest path, level traversal            | Topological sort, permutations, cycle detection |

---

## Difference Between BFS and DFS

| Feature        | BFS        | DFS             |
| -------------- | ---------- | --------------- |
| Data Structure | Queue      | Stack/Recursion |
| Traversal      | Level-wise | Depth-wise      |
| Shortest Path  | Yes        | No              |
| Memory         | More       | Less            |

---

# Interview Questions

## Why BFS is optimal for shortest path in unweighted graph?

Because BFS explores nearest nodes first.

---

## Why Queue is used in BFS?

Queue maintains traversal order level-wise.

---

## Can BFS work recursively?

Not naturally.

DFS is naturally recursive.

---

# Final Revision Points

## BFS Core Concepts

- Queue
- Visited Array
- Level-wise traversal
- Shortest path in unweighted graph

---

## Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(V + E)   |
| Space | O(V)       |

---

## Remember

```text
BFS = Queue
DFS = Stack / Recursion
```
