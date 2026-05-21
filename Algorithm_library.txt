C++ <algorithm> Library – Important Algorithms with Description

--------------------------------------------------
1. Non‑Modifying Sequence Operations
(These algorithms inspect data but do not change it)

all_of()               : Returns true if all elements satisfy a condition.
any_of()               : Returns true if any element satisfies a condition.
none_of()              : Returns true if none satisfy a condition.
for_each()             : Applies a function to every element.
count()                : Counts occurrences of a value.
count_if()             : Counts elements satisfying a condition.
find()                 : Finds a specific value.
find_if()              : Finds element satisfying a condition.
find_if_not()          : Finds element not satisfying a condition.
search()               : Searches for a subsequence.
search_n()             : Finds n consecutive occurrences of a value.
adjacent_find()        : Finds first pair of equal adjacent elements.
find_end()             : Finds last occurrence of a subsequence.
find_first_of()        : Finds first element from another range.
equal()                : Checks if two ranges are equal.
mismatch()             : Finds first position where two ranges differ.

--------------------------------------------------
2. Modifying Sequence Operations
(These algorithms modify container contents)

copy()                 : Copies elements from one range to another.
copy_if()              : Copies elements that satisfy a condition.
copy_n()               : Copies first n elements.
copy_backward()        : Copies elements backwards.
move()                 : Moves elements from one range to another.
move_backward()        : Moves elements backwards.
fill()                 : Fills range with a value.
fill_n()               : Fills first n elements with value.
transform()            : Applies operation and stores result.
generate()             : Generates elements using a function.
generate_n()           : Generates n elements.
replace()              : Replaces all occurrences of a value.
replace_if()           : Replaces elements satisfying condition.
replace_copy()         : Copies while replacing a value.
replace_copy_if()      : Conditional replace during copy.
swap()                 : Swaps two values.
swap_ranges()          : Swaps two ranges.
iter_swap()            : Swaps elements pointed by iterators.
remove()               : Removes a value from range.
remove_if()            : Removes elements satisfying condition.
remove_copy()          : Copies excluding a value.
remove_copy_if()       : Copies excluding elements satisfying condition.
unique()               : Removes consecutive duplicates.
unique_copy()          : Copies unique values.
reverse()              : Reverses elements in a range.
reverse_copy()         : Copies elements in reversed order.
rotate()               : Rotates elements around a pivot.
rotate_copy()          : Copies rotated elements.
shuffle()              : Randomly shuffles elements.
sample()               : Selects random sample from range.

--------------------------------------------------
3. Partitioning Algorithms

partition()            : Rearranges elements based on condition.
stable_partition()     : Same as partition but keeps order.
partition_copy()       : Copies partitioned elements to separate ranges.
is_partitioned()       : Checks if range is partitioned.
partition_point()      : Returns partition boundary.

--------------------------------------------------
4. Sorting Algorithms

sort()                 : Sorts elements in ascending order.
stable_sort()          : Sorts while preserving relative order.
partial_sort()         : Sorts first part of the range.
partial_sort_copy()    : Copies partially sorted elements.
nth_element()          : Places nth smallest element in correct position.
is_sorted()            : Checks if range is sorted.
is_sorted_until()      : Finds first element that breaks sorted order.

--------------------------------------------------
5. Binary Search Algorithms
(Require sorted ranges)

binary_search()        : Checks if element exists in sorted range.
lower_bound()          : Returns first position ≥ value.
upper_bound()          : Returns first position > value.
equal_range()          : Returns range of equal elements.

--------------------------------------------------
6. Set Operations
(Require sorted ranges)

set_union()            : Computes union of two sets.
set_intersection()     : Computes intersection of sets.
set_difference()       : Computes difference of sets.
set_symmetric_difference(): Elements present in one set but not both.
includes()             : Checks if one set includes another.

--------------------------------------------------
7. Heap Operations

make_heap()            : Converts range into a heap.
push_heap()            : Inserts element into heap.
pop_heap()             : Removes largest element from heap.
sort_heap()            : Sorts elements in a heap.
is_heap()              : Checks if range is a heap.
is_heap_until()        : Finds heap boundary.

--------------------------------------------------
8. Min / Max Operations

max()                  : Returns larger of two values.
min()                  : Returns smaller of two values.
minmax()               : Returns both min and max.
max_element()          : Finds largest element in range.
min_element()          : Finds smallest element in range.
minmax_element()       : Finds both min and max element positions.
clamp()                : Restricts value within a range.

--------------------------------------------------
9. Permutation Algorithms

next_permutation()     : Generates next lexicographical permutation.
prev_permutation()     : Generates previous permutation.
is_permutation()       : Checks if two ranges are permutations.

--------------------------------------------------
10. Lexicographical Comparison

lexicographical_compare() : Compares two sequences lexicographically.
lexicographical_compare_three_way() : Three‑way comparison of sequences.

--------------------------------------------------
Note:
These algorithms work with iterators like:

container.begin()
container.end()

Example:

sort(v.begin(), v.end());
reverse(v.begin(), v.end());
find(v.begin(), v.end(), value);