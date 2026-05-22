

# Graph Notes

# Introduction to Graphs

A graph is a non-linear data structure consisting of:

- Vertices (Nodes)
- Edges (Connections)

Graphs are used to represent networks.

Examples:
- Social networks
- Google Maps
- Computer networks
- Flight routes
- Web pages

---

# Basic Terminologies

## Vertex
A point/node in a graph.

Example:

```text
A, B, C
```

---

## Edge
Connection between two vertices.

Example:

```text
A ----- B
```

---

## Degree
Number of edges connected to a vertex.

---

## Path
Sequence of vertices connected by edges.

---

## Cycle
A path that starts and ends at same vertex.

---

## Connected Graph
Every vertex can be reached from every other vertex.

---

## Disconnected Graph
Some vertices cannot be reached.

---

# Types of Graphs

## Undirected Graph
Edges have no direction.

```text
A ----- B
```

Both directions allowed.

---

## Directed Graph (Digraph)

Edges have direction.

```text
A -----> B
```

Travel allowed only from A to B.

---

## Weighted Graph
Edges contain weights/costs.

```text
A --5-- B
```

---

## Unweighted Graph
Edges have no weights.

---

## Cyclic Graph
Contains cycle.

---

## Acyclic Graph
No cycle exists.

---

## Complete Graph
Every vertex connected to every other vertex.

---

## Null Graph
Graph with vertices but no edges.

---

# Graph Representation

Two main methods:

1. Adjacency Matrix
2. Adjacency List

---

# Adjacency Matrix

Uses 2D array.

If edge exists:

```text
1
```

Else:

```text
0
```

---

## Example

```text
0 ----- 1
|       |
|       |
2 ----- 3
```

Matrix:

```text
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

---

## Adjacency Matrix Code

```cpp
#include <iostream>
using namespace std;

int main() {

    int n = 4;

    int graph[4][4] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
```

---

## Complexity

| Operation | Complexity |
|---|---|
| Add Edge | O(1) |
| Search Edge | O(1) |
| Space | O(V²) |

---

## Advantages

- Simple implementation
- Fast edge checking

---

## Disadvantages

- Wastes space
- Bad for sparse graphs

---

# Adjacency List

Stores neighbors of every node.

---

## Example

```text
0 : 1 2
1 : 0 3
2 : 0 3
3 : 1 2
```

---

## Adjacency List Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 4;

    vector<int> graph[n];

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    for(int i = 0; i < n; i++) {

        cout << i << " : ";

        for(int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
```

---

## Complexity

| Operation | Complexity |
|---|---|
| Add Edge | O(1) |
| Search Edge | O(V) |
| Space | O(V + E) |

---

## Advantages

- Space efficient
- Best for sparse graphs

---

## Disadvantages

- Edge search slower

---

# Breadth First Search (BFS)

## Basic Idea

Visit nodes level by level.

Uses:

```text
Queue
```

---

## BFS Algorithm

1. Start node into queue.
2. Mark visited.
3. Pop front node.
4. Visit neighbors.
5. Repeat.

---

## BFS Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> graph[], int start, int n) {

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

int main() {

    int n = 5;

    vector<int> graph[n];

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    bfs(graph, 0, n);

    return 0;
}
```

---

## BFS Complexity

| Complexity | Value |
|---|---|
| Time | O(V + E) |
| Space | O(V) |

---

## Applications of BFS

- Shortest path in unweighted graph
- Level order traversal
- Network broadcasting

---

# Depth First Search (DFS)

## Basic Idea

Go deep first.

Uses:

```text
Recursion / Stack
```

---

## DFS Algorithm

1. Visit node.
2. Mark visited.
3. Recursively visit neighbors.

---

## DFS Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> graph[], int node, vector<bool> &visited) {

    visited[node] = true;

    cout << node << " ";

    for(int neighbor : graph[node]) {

        if(!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {

    int n = 5;

    vector<int> graph[n];

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    vector<bool> visited(n, false);

    dfs(graph, 0, visited);

    return 0;
}
```

---

## DFS Complexity

| Complexity | Value |
|---|---|
| Time | O(V + E) |
| Space | O(V) |

---

## Applications of DFS

- Cycle detection
- Topological sorting
- Maze solving
- Connected components

---

# BFS vs DFS Comparison

| Feature | BFS | DFS |
|---|---|---|
| Data Structure | Queue | Stack/Recursion |
| Traversal Style | Level-wise | Depth-wise |
| Shortest Path | Yes | No |
| Memory Usage | More | Less |
| Speed | Slower sometimes | Faster sometimes |

---

# Important Graph Concepts

# Tree

A connected graph with no cycles.

Properties:
- n vertices
- n-1 edges

---

# Bipartite Graph

Vertices divided into two sets.

No same-set connection.

---

# DAG (Directed Acyclic Graph)

Directed graph with no cycles.

Used in:
- Topological sort
- Scheduling

---

# Graph Traversal Complexity

## Why BFS and DFS are O(V + E)?

Because:
- every vertex visited once
- every edge checked once

---

# Sparse vs Dense Graph

## Sparse Graph
Few edges.

Adjacency list preferred.

---

## Dense Graph
Many edges.

Adjacency matrix preferred.

---

# Common Interview Questions

## Why BFS gives shortest path?
Because BFS explores level by level.

---

## Why DFS uses recursion?
Because recursion naturally behaves like stack.

---

## Why adjacency list better for sparse graph?
Less memory usage.

---

## Why adjacency matrix faster for edge search?
Direct indexing.

---

# Common Mistakes

## Forgetting Visited Array
May cause infinite traversal.

---

## Wrong Graph Size
Always initialize correctly.

---

## Missing Both Edges in Undirected Graph

Correct:

```cpp
graph[u].push_back(v);
graph[v].push_back(u);
```

---

# Final Revision Points

## BFS
- Queue
- Level order
- Shortest path

---

## DFS
- Recursion
- Go deep first
- Backtracking

---

## Adjacency Matrix
- O(V²) space
- Fast edge lookup

---

## Adjacency List
- O(V + E) space
- Memory efficient
