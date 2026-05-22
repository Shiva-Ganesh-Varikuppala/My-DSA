

# Queue Data Structure Notes

## What is a Queue?

A Queue is a linear data structure that follows:

```text
FIFO (First In First Out)
```

The element inserted first is removed first.

---

# Real Life Examples

- People standing in line
- Ticket counters
- Printer queue
- CPU scheduling
- Call center systems

---

# Basic Operations of Queue

| Operation | Meaning |
|---|---|
| push() / enqueue() | Insert element |
| pop() / dequeue() | Remove front element |
| front() | Access front element |
| back() | Access last element |
| empty() | Check if queue is empty |
| size() | Number of elements |

---

# Queue Representation

```text
Front                Rear
 ↓                     ↓
| 10 | 20 | 30 | 40 |
```

---

# Enqueue Operation

Adds element at rear.

Before:

```text
10 20 30
```

Enqueue `40`

After:

```text
10 20 30 40
```

---

# Dequeue Operation

Removes element from front.

Before:

```text
10 20 30 40
```

Dequeue:

```text
10 removed
```

After:

```text
20 30 40
```

---

# Front Operation

Returns front element.

```cpp
q.front();
```

---

# Queue Using Array

## Implementation

```cpp
#include<iostream>
using namespace std;

class Queue {
    int arr[100];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    void push(int x) {
        rearIndex++;
        arr[rearIndex] = x;
    }

    void pop() {
        if(frontIndex > rearIndex) {
            cout << "Queue Underflow\n";
            return;
        }

        frontIndex++;
    }

    int front() {
        return arr[frontIndex];
    }

    bool empty() {
        return frontIndex > rearIndex;
    }
};
```

---

# Queue Using STL

```cpp
#include<iostream>
#include<queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;

    q.pop();

    cout << q.front();

    return 0;
}
```

Output:

```text
10
20
```

---

# Queue STL Functions

| Function | Description |
|---|---|
| push(x) | Insert element |
| pop() | Remove front |
| front() | Access front |
| back() | Access rear |
| empty() | Returns true if empty |
| size() | Returns size |

---

# Time Complexity of Queue Operations

| Operation | Complexity |
|---|---|
| push() | O(1) |
| pop() | O(1) |
| front() | O(1) |
| back() | O(1) |
| empty() | O(1) |
| size() | O(1) |

---

# Queue Overflow

Occurs when queue becomes full.

---

# Queue Underflow

Occurs when removing from empty queue.

---

# Queue Using Linked List

```cpp
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = rearNode = NULL;
    }

    void push(int val) {

        Node* temp = new Node(val);

        if(rearNode == NULL) {
            frontNode = rearNode = temp;
            return;
        }

        rearNode->next = temp;
        rearNode = temp;
    }

    void pop() {

        if(frontNode == NULL) return;

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if(frontNode == NULL)
            rearNode = NULL;

        delete temp;
    }

    int front() {
        return frontNode->data;
    }
};
```

---

# Circular Queue

A queue where last position connects back to first position.

Prevents memory wastage.

---

# Circular Queue Representation

```text
0 → 1 → 2 → 3
↑         ↓
← ← ← ← ←
```

---

# Circular Queue Advantages

- Efficient memory usage
- No shifting required
- Faster implementation

---

# Deque (Double Ended Queue)

Insertion and deletion possible from both ends.

---

# Types of Deque

---

## Input Restricted Deque

Insertion from one end only.

---

## Output Restricted Deque

Deletion from one end only.

---

# STL Deque

```cpp
#include<iostream>
#include<deque>
using namespace std;

int main() {

    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);

    cout << dq.front() << endl;
    cout << dq.back();

    return 0;
}
```

---

# Priority Queue

Special queue where highest priority element is processed first.

Implemented using heap.

---

# Max Heap Priority Queue

```cpp
priority_queue<int> pq;
```

Largest element at top.

---

# Min Heap Priority Queue

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Smallest element at top.

---

# Priority Queue Operations

| Operation | Complexity |
|---|---|
| push() | O(log n) |
| pop() | O(log n) |
| top() | O(1) |

---

# Applications of Queue

---

## 1. CPU Scheduling

Processes handled in order.

---

## 2. BFS Traversal

Breadth First Search uses queue.

---

## 3. Printer Queue

Print jobs processed sequentially.

---

## 4. Call Center Systems

Customers handled in order.

---

## 5. Network Packet Processing

Packets processed in sequence.

---

# Queue in BFS

Queue helps process nodes level by level.

---

# BFS Code Example

```cpp
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int start, vector<int> adj[], int n) {

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

# Difference Between Stack and Queue

| Stack | Queue |
|---|---|
| LIFO | FIFO |
| Insert/Delete at top | Insert rear, delete front |
| push/pop | enqueue/dequeue |
| Used in recursion | Used in scheduling |

---

# Double Ended Queue Applications

- Sliding Window Maximum
- LRU Cache
- Palindrome checking

---

# Monotonic Queue

Queue maintaining sorted order.

Used in:

- Sliding Window Maximum
- Optimization problems

---

# Sliding Window Maximum

Classic deque problem.

Find maximum in every window.

---

# Important Interview Problems

1. Implement Queue using Stack
2. Implement Stack using Queue
3. Circular Queue
4. Sliding Window Maximum
5. Rotten Oranges
6. BFS Traversal
7. First Non-Repeating Character
8. Generate Binary Numbers
9. LRU Cache
10. Task Scheduler

---

# Complexity Summary

| Operation | Time |
|---|---|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Front | O(1) |
| Rear | O(1) |
| Search | O(n) |

---

# Common Mistakes

---

## Mistake 1

Calling `front()` on empty queue.

---

## Mistake 2

Confusing stack with queue.

---

## Mistake 3

Not handling overflow/underflow.

---

## Mistake 4

Incorrect circular queue indexing.

---

# Real Interview Insights

Interviewers expect:

- FIFO understanding
- Queue STL usage
- BFS understanding
- Circular queue concepts
- Deque optimization problems
- Priority queue usage

---

# Golden Rules

1. Queue follows FIFO
2. Insert at rear, delete from front
3. Most queue operations are O(1)
4. BFS heavily depends on queue
5. Deque and priority queue are interview favorites

---

# Final Summary

Queue is one of the most important linear data structures.

Most important concepts:

```text
FIFO
Enqueue
Dequeue
Front
Rear
Deque
Priority Queue
Circular Queue
```

Queues are heavily used in:

- BFS traversal
- Operating systems
- Scheduling systems
- Networking
- Competitive programming
