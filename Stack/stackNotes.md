

# Stack Data Structure Notes

## What is a Stack?

A Stack is a linear data structure that follows:

```text
LIFO (Last In First Out)
```

The element inserted last is removed first.

---

# Real Life Examples

- Stack of plates
- Browser back button
- Undo/Redo operations
- Function call stack
- Recursion

---

# Basic Operations of Stack

| Operation | Meaning |
|---|---|
| push() | Insert element |
| pop() | Remove top element |
| top() | Access top element |
| empty() | Check if stack is empty |
| size() | Number of elements |

---

# Stack Representation

```text
Top
 ↓
| 40 |
| 30 |
| 20 |
| 10 |
```

---

# Push Operation

Adds element at the top.

Example:

Before:

```text
10 20 30
```

Push `40`

After:

```text
10 20 30 40
```

---

# Pop Operation

Removes top element.

Before:

```text
10 20 30 40
```

Pop:

```text
40 removed
```

After:

```text
10 20 30
```

---

# Top Operation

Returns topmost element.

```cpp
st.top();
```

---

# Stack Using Array

## Implementation

```cpp
#include<iostream>
using namespace std;

class Stack {
    int arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int x) {
        topIndex++;
        arr[topIndex] = x;
    }

    void pop() {
        if(topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }
};
```

---

# Stack Using STL

```cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;

    st.pop();

    cout << st.top();

    return 0;
}
```

Output:

```text
30
20
```

---

# Stack STL Functions

| Function | Description |
|---|---|
| push(x) | Insert element |
| pop() | Remove top |
| top() | Access top |
| empty() | Returns true if empty |
| size() | Returns size |

---

# Time Complexity of Stack Operations

| Operation | Complexity |
|---|---|
| push() | O(1) |
| pop() | O(1) |
| top() | O(1) |
| empty() | O(1) |
| size() | O(1) |

---

# Stack Overflow

Occurs when pushing into full stack.

Example:

```text
Stack capacity exceeded
```

---

# Stack Underflow

Occurs when popping from empty stack.

---

# Dynamic Stack

Using linked list avoids fixed size limitation.

---

# Stack Using Linked List

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

class Stack {
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    void push(int val) {
        Node* temp = new Node(val);
        temp->next = topNode;
        topNode = temp;
    }

    void pop() {
        if(topNode == NULL) return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        return topNode->data;
    }
};
```

---

# Applications of Stack

---

## 1. Function Calls

Every function call is stored in call stack.

---

## 2. Recursion

Recursive calls use stack memory.

---

## 3. Expression Evaluation

Examples:

- Infix
- Prefix
- Postfix

---

## 4. Undo/Redo

Editors use stack.

---

## 5. Browser Navigation

Back/forward functionality.

---

# Parentheses Matching Problem

Check balanced brackets.

Example:

```text
({[]}) → Valid
([)] → Invalid
```

---

# Balanced Parentheses Code

```cpp
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for(char ch : s) {

        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {

            if(st.empty()) return false;

            if(ch == ')' && st.top() != '(') return false;
            if(ch == '}' && st.top() != '{') return false;
            if(ch == ']' && st.top() != '[') return false;

            st.pop();
        }
    }

    return st.empty();
}
```

---

# Infix, Prefix and Postfix

---

## Infix

Operator between operands.

Example:

```text
A + B
```

---

## Prefix

Operator before operands.

Example:

```text
+AB
```

---

## Postfix

Operator after operands.

Example:

```text
AB+
```

---

# Advantages of Stack

- Fast operations
- Simple implementation
- Useful in recursion
- Efficient memory access

---

# Disadvantages of Stack

- Limited access
- Only top accessible
- Fixed size in arrays

---

# Monotonic Stack

Special stack maintaining sorted order.

Types:

- Increasing Stack
- Decreasing Stack

Used in:

- Next Greater Element
- Largest Rectangle in Histogram
- Stock Span Problem

---

# Next Greater Element

Problem:

Find first greater element on right.

Example:

```text
Input:  [2,1,3]
Output: [3,3,-1]
```

---

# Next Greater Element Code

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(nums[i]);
    }

    return ans;
}
```

---

# Stack Memory vs Heap Memory

| Stack Memory | Heap Memory |
|---|---|
| Automatic allocation | Manual allocation |
| Faster | Slower |
| Limited size | Large size |
| Stores local variables | Stores dynamic memory |

---

# Call Stack

Stores:

- Function calls
- Local variables
- Return addresses

---

# Recursion Stack Space

Recursive function:

```cpp
fun(n-1);
```

Space Complexity:

```text
O(n)
```

because stack frames are created.

---

# Important Interview Problems

1. Valid Parentheses
2. Min Stack
3. Next Greater Element
4. Largest Rectangle Histogram
5. Stock Span Problem
6. Evaluate Postfix Expression
7. Implement Stack using Queue
8. Implement Queue using Stack
9. Daily Temperatures
10. Trapping Rain Water

---

# Complexity Summary

| Operation | Time |
|---|---|
| Push | O(1) |
| Pop | O(1) |
| Top | O(1) |
| Search | O(n) |

---

# Common Mistakes

---

## Mistake 1

Calling `top()` on empty stack.

---

## Mistake 2

Forgetting to pop elements.

---

## Mistake 3

Stack overflow due to deep recursion.

---

# Real Interview Insights

Interviewers expect:

- Understanding of LIFO
- STL stack usage
- Stack-based problem solving
- Monotonic stack concepts
- Expression conversion/evaluation

---

# Golden Rules

1. Stack follows LIFO
2. Push/pop happen only at top
3. Most stack operations are O(1)
4. Recursion internally uses stack
5. Monotonic stacks are extremely important in interviews

---

# Final Summary

Stack is one of the most important linear data structures.

Most important concepts:

```text
Push
Pop
Top
LIFO
Monotonic Stack
Recursion Stack
Balanced Parentheses
```

Stacks are heavily used in:

- DSA interviews
- Competitive programming
- Compiler design
- Expression evaluation
- System programming