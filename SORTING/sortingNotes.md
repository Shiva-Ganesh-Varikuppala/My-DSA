
# Sorting Algorithms Notes

## Introduction to Sorting

Sorting means arranging data in a particular order.

Types:
- Ascending Order → Small to Large
- Descending Order → Large to Small

Example:

```cpp
1 5 2 4 3
```

After sorting:

```cpp
1 2 3 4 5
```

---

# Why Sorting is Important

Sorting is used in:
- Searching
- Databases
- Data Analysis
- Binary Search
- Competitive Programming
- Operating Systems
- E-commerce Filtering
- Ranking Systems

---

# Classification of Sorting Algorithms

## Based on Memory Usage

### 1. In-Place Sorting
Uses constant extra memory.

Examples:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Quick Sort

### 2. Out-Place Sorting
Uses extra memory.

Examples:
- Merge Sort

---

## Based on Stability

### Stable Sorting
Maintains relative order of equal elements.

Examples:
- Bubble Sort
- Insertion Sort
- Merge Sort

### Unstable Sorting
May change relative order.

Examples:
- Selection Sort
- Quick Sort

---

# Important Terminologies

## Time Complexity
Measures total operations performed.

## Space Complexity
Measures extra memory used.

## Best Case
Minimum time taken.

## Average Case
Expected time.

## Worst Case
Maximum time taken.

---

# Bubble Sort

## Basic Idea
Largest element moves to the end in every pass.

Just like bubbles rise upward.

---

## Working

Example:

```cpp
5 1 4 2 8
```

Pass 1:

```cpp
1 4 2 5 8
```

Pass 2:

```cpp
1 2 4 5 8
```

Array becomes sorted.

---

## Algorithm

1. Compare adjacent elements.
2. Swap if left element is greater.
3. Repeat for all elements.
4. After each pass, largest element reaches correct position.

---

## Bubble Sort Code

```cpp
#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++) {

        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(swapped == false) {
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Bubble Sort Complexities

| Case | Complexity |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

---

## Bubble Sort Advantages

- Easy to understand
- Stable
- In-place

---

## Bubble Sort Disadvantages

- Very slow for large data
- Too many swaps

---

# Selection Sort

## Basic Idea
Find smallest element and place it at correct position.

---

## Working

Example:

```cpp
64 25 12 22 11
```

Pass 1:
Find minimum = 11

```cpp
11 25 12 22 64
```

Pass 2:
Find minimum = 12

```cpp
11 12 25 22 64
```

Continue until sorted.

---

## Algorithm

1. Find minimum element.
2. Swap with current index.
3. Repeat for remaining array.

---

## Selection Sort Code

```cpp
#include <iostream>
using namespace std;

int main() {

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < n; j++) {

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Selection Sort Complexities

| Case | Complexity |
|---|---|
| Best | O(n²) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

---

## Selection Sort Advantages

- Less swaps
- In-place
- Simple

---

## Selection Sort Disadvantages

- Slow
- Not stable

---

# Insertion Sort

## Basic Idea
Insert every element into its correct position.

Works like arranging playing cards.

---

## Working

Example:

```cpp
5 2 4 6 1 3
```

Take one element at a time and insert properly.

---

## Algorithm

1. Assume first element is sorted.
2. Pick next element.
3. Shift larger elements.
4. Insert current element.

---

## Insertion Sort Code

```cpp
#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 1; i < n; i++) {

        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Insertion Sort Complexities

| Case | Complexity |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

---

## Advantages

- Stable
- Efficient for small arrays
- Adaptive
- In-place

---

## Disadvantages

- Slow for large data

---

# Merge Sort

# Divide and Conquer Concept

Merge Sort uses Divide and Conquer.

Steps:

1. Divide array into halves.
2. Sort both halves recursively.
3. Merge sorted halves.

---

## Merge Sort Tree

Example:

```cpp
8 3 5 4 7 6 1 2
```

Divide repeatedly until single elements remain.

Then merge them in sorted order.

---

## Merge Sort Code

```cpp
#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end) {

    int n1 = mid - st + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for(int i = 0; i < n1; i++) {
        left[i] = arr[st + i];
    }

    for(int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = st;

    while(i < n1 && j < n2) {

        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int st, int end) {

    if(st >= end) {
        return;
    }

    int mid = st + (end - st) / 2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, st, mid, end);
}

int main() {

    int arr[] = {8, 3, 5, 4, 7, 6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Merge Sort Complexities

| Case | Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |
| Space | O(n) |

---

## Merge Sort Advantages

- Very efficient
- Stable
- Guaranteed O(n log n)
- Good for linked lists

---

## Merge Sort Disadvantages

- Extra memory required
- Recursive overhead

---

# Quick Sort

## Basic Idea

1. Pick a pivot.
2. Place pivot at correct position.
3. Smaller elements on left.
4. Larger elements on right.
5. Repeat recursively.

---

## Pivot

Pivot can be:
- First element
- Last element
- Random element
- Middle element

---

## Partitioning

Partition means arranging:

```cpp
Smaller | Pivot | Larger
```

---

## Quick Sort Code

```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int st, int end) {

    int pivot = arr[end];
    int idx = st - 1;

    for(int i = st; i < end; i++) {

        if(arr[i] < pivot) {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

void quickSort(int arr[], int st, int end) {

    if(st < end) {

        int pivotIndex = partition(arr, st, end);

        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main() {

    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

## Quick Sort Complexities

| Case | Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |
| Space | O(log n) |

---

## Why Worst Case Happens?

Worst case occurs when pivot becomes:
- smallest element
- largest element

Example:

```cpp
1 2 3 4 5
```

Already sorted array with bad pivot selection.

---

## Quick Sort Advantages

- Very fast in practice
- In-place
- Cache friendly

---

## Quick Sort Disadvantages

- Worst case O(n²)
- Recursive calls
- Unstable

---

# Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable |
|---|---|---|---|---|---|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | No |

---

# When to Use Which Sorting?

## Bubble Sort
Use for:
- Learning basics
- Very small datasets

---

## Selection Sort
Use when:
- Memory writes are costly

---

## Insertion Sort
Use when:
- Data is nearly sorted
- Small arrays

---

## Merge Sort
Use when:
- Stability required
- Guaranteed performance needed
- Large datasets

---

## Quick Sort
Use when:
- Fast average performance required
- Memory usage should be low

---

# Important Interview Questions

## Why is Merge Sort stable?
Because equal elements maintain order during merge.

---

## Why is Quick Sort faster practically?
Because of:
- cache efficiency
- low constant factors
- in-place operations

---

## Why does Merge Sort need extra space?
Temporary arrays are created during merging.

---

## Why is Bubble Sort adaptive?
Because optimized version stops early if array becomes sorted.

---

## Why is Selection Sort not stable?
Swapping may change relative order.

---

# Common Mistakes

## Bubble Sort
Wrong inner loop range.

Correct:

```cpp
j < n - i - 1
```

---

## Binary Overflow in Mid

Wrong:

```cpp
mid = (st + end) / 2
```

Correct:

```cpp
mid = st + (end - st) / 2
```

---

## Merge Sort Base Condition

Correct:

```cpp
if(st >= end)
```

---

# Recursion Depth

## Merge Sort
Depth:

```cpp
log n
```

## Quick Sort
Average depth:

```cpp
log n
```

Worst depth:

```cpp
n
```

---

# Final Revision Points

## Bubble Sort
- Adjacent swaps
- Largest reaches end
- Stable

---

## Selection Sort
- Minimum selection
- Less swaps
- Unstable

---

## Insertion Sort
- Insert correctly
- Best for nearly sorted arrays
- Stable

---

## Merge Sort
- Divide and conquer
- Stable
- Extra space needed

---

## Quick Sort
- Pivot based
- Fast practically
- Worst O(n²)
