 
# Linked Lists Complete Notes for DSA

---

## 1. Introduction to Linked Lists

### What is a Linked List
A **linked list** is a linear data structure consisting of nodes connected through pointers. Each node stores data and a reference (pointer) to the next node in the sequence.

### Real World Examples
- Music playlist navigation
- Browser history
- Undo/Redo operations
- Image viewers
- Dynamic memory allocation

### Why Linked Lists are Used
- Dynamic size allocation
- Efficient insertion and deletion
- No need for contiguous memory
- Useful for implementing stacks, queues, and graphs

### Basic Idea
Each node contains:
```
Node:
  - Data
  - Pointer to next node
```

---

## 2. Terminology

| Term | Definition |
|--------|------------|
| Node | Basic element containing data and pointer(s) |
| Head | First node of the linked list |
| Tail | Last node of the linked list |
| Next Pointer | Stores address of next node |
| Previous Pointer | Stores address of previous node |
| Null | Indicates end of list |
| Traversal | Visiting nodes sequentially |
| Length | Number of nodes in the list |
| Empty List | List with no nodes |
| Circular List | Last node points back to first node |

---

## 3. Types of Linked Lists

- **Singly Linked List (SLL):** Each node points to next node.
- **Doubly Linked List (DLL):** Each node has next and previous pointers.
- **Circular Singly Linked List (CSLL):** Tail points to head.
- **Circular Doubly Linked List (CDLL):** Tail connects to head and vice versa.
- **Header Linked List:** Contains special header node.

---

## 4. Singly Linked List Fundamentals

### Structure Definition in C++
```cpp
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
```

### Visualization
```
10 -> 20 -> 30 -> 40 -> NULL
```

### Properties
- Sequential access only
- Dynamic memory allocation
- Extra memory required for pointers

---

## 5. Linked List Representation

| Representation | Description |
|---------------|-------------|
| Singly Linked List | One pointer per node |
| Doubly Linked List | Two pointers per node |
| Circular Linked List | Tail connected to head |
| Header Linked List | Extra starting node |

---

## 6. Traversal

### Iterative Traversal
```cpp
void traverse(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

### Recursive Traversal
```cpp
void traverse(Node* head) {
    if(head == nullptr)
        return;

    cout << head->data << " ";
    traverse(head->next);
}
```

### Complexity
- Time: O(n)
- Space: O(1) iterative
- Space: O(n) recursive stack

---

## 7. Insertion Operations

### Insert at Beginning
- Create node
- Point new node to current head
- Update head

### Insert at End
- Traverse to tail
- Attach new node

### Insert at Position
- Reach previous node
- Adjust pointers

### Complexity

| Operation | Complexity |
|------------|------------|
| Beginning | O(1) |
| End | O(n) |
| Position | O(n) |

---

## 8. Deletion Operations

### Delete First Node
- Move head to next node
- Delete old head

### Delete Last Node
- Reach second last node
- Set next as NULL

### Delete by Value
- Search node
- Update links
- Delete node

### Complexity

| Operation | Complexity |
|------------|------------|
| Beginning | O(1) |
| End | O(n) |
| By Value | O(n) |

---

## 9. Important Linked List Problems

- Find length of linked list
- Search an element
- Find middle node
- Reverse linked list
- Detect cycle
- Remove cycle
- Merge two sorted lists
- Find intersection point
- Check palindrome
- Remove duplicates
- Rotate linked list
- Segregate even and odd nodes
- Clone linked list with random pointer
- Flatten linked list
- Sort linked list

---

## 10. Doubly Linked List (DLL)

### Structure
```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
```

### Advantages
- Bidirectional traversal
- Easier deletion
- Better for navigation problems

### Disadvantages
- Extra memory usage
- More pointer manipulation

### Complexity

| Operation | Complexity |
|------------|------------|
| Insert Front | O(1) |
| Delete Node | O(1) |
| Search | O(n) |

---

## 11. Circular Linked List

### Concept
Last node points back to head.

```
10 -> 20 -> 30
^           |
|___________|
```

### Applications
- Round Robin Scheduling
- Multiplayer games
- Circular queues
- Music playlists

### Complexity
Same as singly linked list.

---

## 12. Fast and Slow Pointer Technique

### Idea
Use two pointers:
- Slow moves one step
- Fast moves two steps

### Applications
- Find middle node
- Detect cycle
- Find cycle start
- Check palindrome

### Complexity
- Time: O(n)
- Space: O(1)

---

## 13. Cycle Detection

### Floyd's Cycle Detection Algorithm

Steps:
1. Initialize slow and fast.
2. Move slow by one step.
3. Move fast by two steps.
4. If they meet, cycle exists.

### Complexity
- Time: O(n)
- Space: O(1)

---

## 14. Reversing Linked Lists

### Iterative Method
Use:
- prev
- current
- next

### Complexity
- Time: O(n)
- Space: O(1)

### Recursive Method
Reverse remaining list and reconnect.

---

## 15. Advanced Linked List Problems

- Reverse in groups of K
- LRU Cache implementation
- Merge K sorted lists
- Copy list with random pointer
- Flatten multilevel linked list
- Add two numbers represented by lists
- Multiply linked lists
- Segregate nodes
- Partition list

---

## 16. Linked List Based Data Structures

### Stack Using Linked List
- Push at head
- Pop from head
- O(1) operations

### Queue Using Linked List
- Insert at rear
- Delete from front
- O(1) operations

### Deque Using DLL
- Insert/Delete from both ends

---

## 17. Generic Algorithms

- Traversal
- Searching
- Counting nodes
- Reversal
- Splitting list
- Merging lists
- Sorting lists

---

## 18. Sorting Linked Lists

### Merge Sort
Preferred for linked lists.

### Why?
- No random access needed
- Easy splitting using slow-fast pointers

### Complexity
- Time: O(n log n)
- Space: O(log n)

### Quick Sort
Possible but generally less preferred.

---

## 19. Competitive Programming Concepts

- Slow-Fast Pointer Technique
- Dummy Nodes
- Two Pointer Technique
- Linked List Simulation
- Circular List Handling
- Pointer Manipulation Tricks

---

## 20. Linked Lists in Graph Theory

- Adjacency List Representation
- Dynamic Edge Storage
- Sparse Graph Representation

---

## 21. Complexity Cheat Sheet

| Operation | Singly LL | Doubly LL |
|------------|-----------|------------|
| Access | O(n) | O(n) |
| Search | O(n) | O(n) |
| Insert Front | O(1) | O(1) |
| Insert End | O(n) | O(n) |
| Delete Front | O(1) | O(1) |
| Delete End | O(n) | O(1) if tail available |
| Space per Node | 1 Pointer | 2 Pointers |

---

## 22. Interview Preparation Section

### Most Asked Linked List Questions

- Reverse linked list
- Detect cycle
- Merge sorted lists
- Remove nth node from end
- Find middle node
- Intersection of two lists
- LRU Cache
- Copy random pointer list
- Reverse in K groups
- Flatten linked list

### Common Mistakes

- Forgetting NULL checks
- Losing node references
- Incorrect pointer updates
- Memory leaks after deletion
- Infinite loops in circular lists

### Problem Solving Strategy

- Draw the linked list first
- Track pointers visually
- Handle edge cases
- Use dummy nodes when necessary
- Verify pointer updates carefully

---

## 23. Revision Sheet

| Topic | Key Points |
|---------|-----------|
| Basics | Node, Head, Tail |
| SLL | One pointer per node |
| DLL | Previous and next pointers |
| Circular LL | Tail points to head |
| Traversal | Sequential access |
| Insertion | Beginning, End, Position |
| Deletion | Beginning, End, Value |
| Fast-Slow Pointer | Middle, Cycle Detection |
| Reversal | Iterative and Recursive |
| Sorting | Merge Sort |
| Advanced Problems | K-Reverse, LRU, Clone List |

---

*End of Linked Lists Complete Notes for DSA*