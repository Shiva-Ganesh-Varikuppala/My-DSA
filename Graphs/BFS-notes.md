

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

| Representation | Complexity |
|---|---|
| Adjacency Matrix | O(V²) |
| Adjacency List | O(V + E) |

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

# Difference Between BFS and DFS

| Feature | BFS | DFS |
|---|---|---|
| Data Structure | Queue | Stack/Recursion |
| Traversal | Level-wise | Depth-wise |
| Shortest Path | Yes | No |
| Memory | More | Less |

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