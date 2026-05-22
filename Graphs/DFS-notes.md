# Depth First Search (DFS)

# Introduction

Depth First Search (DFS) is a graph traversal algorithm.

DFS explores:

```text
as deep as possible first
```

before backtracking.

---

# Basic Idea of DFS

DFS starts from a source node and:

1. Visits a node
2. Goes to one of its neighbors
3. Continues going deeper
4. Backtracks when no unvisited neighbor remains

---

# Real Life Analogy

Imagine exploring a maze.

You keep moving forward until:

```text
no path exists
```

Then you return back.

This returning process is called:

```text
Backtracking
```

---

# Data Structures Used in DFS

DFS uses:

```text
Recursion or Stack
```

because recursion internally uses stack memory.

---

# Important Components

## 1. Visited Array

Prevents revisiting nodes.

Without visited array:
- infinite recursion may happen
- repeated traversal occurs

---

## 2. Recursion Stack

Stores function calls during DFS traversal.

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

# DFS Traversal Order

Starting from:

```text
0
```

One possible DFS traversal:

```text
0 1 3 4 2 5
```

DFS order may vary depending on neighbor order.

---

# Step-by-Step Dry Run

## Step 1

Visit:

```text
0
```

Go deeper to:

```text
1
```

---

## Step 2

Visit:

```text
1
```

Go deeper to:

```text
3
```

---

## Step 3

Visit:

```text
3
```

No unvisited neighbors.

Backtrack to:

```text
1
```

---

## Step 4

Visit next neighbor:

```text
4
```

Continue similarly.

---

# DFS Algorithm

## Steps

1. Visit node
2. Mark visited
3. Traverse all neighbors
4. Recursively visit unvisited neighbors

---

# DFS Recursive Code

```cpp
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited){

    visited[node] = true;

    cout << node << " ";

    for(int neighbor : graph[node]){

        if(!visited[neighbor]){
            dfs(graph, neighbor, visited);
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

    vector<bool> visited(n, false);

    dfs(graph, 0, visited);

    return 0;
}
```

---

# Output

```text
0 1 3 4 2 5
```

---

# DFS Using Stack (Iterative DFS)

DFS can also be implemented using stack.

---

# Iterative DFS Code

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

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

    vector<bool> visited(n, false);

    stack<int> st;

    st.push(0);

    while(!st.empty()){

        int node = st.top();
        st.pop();

        if(visited[node]){
            continue;
        }

        visited[node] = true;

        cout << node << " ";

        for(int neighbor : graph[node]){

            if(!visited[neighbor]){
                st.push(neighbor);
            }
        }
    }

    return 0;
}
```

---

# DFS Complexity

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

Recursive DFS:

genui{"math_block_widget_always_prefetch_v2":{"content":"O(V)"}}

because recursion stack may store all vertices.

---

# Why DFS Uses Recursion Naturally?

Because recursion automatically remembers:

```text
where to return
```

after reaching dead end.

---

# Backtracking in DFS

DFS backtracks when:

```text
no unvisited neighbor exists
```

Example:

```text
0 → 1 → 3
```

After 3:

```text
backtrack to 1
```

---

# DFS Traversal Tree

DFS creates:

```text
Depth First Tree
```

---

# Applications of DFS

## 1. Cycle Detection

---

## 2. Topological Sorting

---

## 3. Connected Components

---

## 4. Maze Solving

---

## 5. Backtracking Problems

---

## 6. Path Finding

---

## 7. Strongly Connected Components

---

# DFS for Disconnected Graph

Single DFS may not visit all nodes.

Use:

```cpp
for(int i = 0; i < n; i++){

    if(!visited[i]){
        dfs(graph, i, visited);
    }
}
```

---

# BFS vs DFS Comparison

| Feature | BFS | DFS |
|---|---|---|
| Data Structure | Queue | Stack/Recursion |
| Traversal | Level-wise | Depth-wise |
| Shortest Path | Yes | No |
| Memory Usage | More | Less |
| Backtracking | No | Yes |

---

# Recursive Call Flow Example

For:

```text
0 → 1 → 3
```

Call stack becomes:

```text
dfs(0)
  dfs(1)
    dfs(3)
```

Then returns back upward.

---

# Common Mistakes

## 1. Forgetting Visited Array

Causes infinite recursion.

---

## 2. Marking Visited Late

Wrong:

```cpp
for(int neighbor : graph[node]){
    dfs(graph, neighbor, visited);
}
visited[node] = true;
```

Correct:

```cpp
visited[node] = true;
```

before recursive calls.

---

## 3. Stack Overflow

Very deep recursion may cause stack overflow.

---

## 4. Not Handling Disconnected Graph

Some nodes remain unvisited.

---

# DFS on Matrix vs List

| Representation | Complexity |
|---|---|
| Adjacency Matrix | O(V²) |
| Adjacency List | O(V + E) |

Adjacency list is preferred.

---

# Interview Questions

## Why DFS is useful for cycle detection?

Because DFS naturally tracks traversal path.

---

## Why recursion suits DFS?

Because recursion automatically behaves like stack.

---

## Can DFS find shortest path?

Not guaranteed.

BFS is preferred for shortest path in unweighted graph.

---

# DFS vs Tree Traversals

DFS is similar to:
- preorder traversal
- inorder traversal
- postorder traversal

in trees.

---

# Final Revision Points

## DFS Core Concepts

- Recursion
- Stack
- Backtracking
- Go deep first

---

## Complexity

| Type | Complexity |
|---|---|
| Time | O(V + E) |
| Space | O(V) |

---

## Remember

```text
BFS = Queue
DFS = Stack / Recursion
```
