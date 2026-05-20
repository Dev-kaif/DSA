https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

# Segregate 0s and 1s

## Problem Statement

Given an array `arr[]` consisting of only `0`s and `1`s. Modify the array in-place to segregate `0`s onto the left side and `1`s onto the right side of the array.

---

## Examples

### Example 1

Input:
```cpp
arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
````

Output:

```cpp
[0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
```

Explanation:

After segregation, all the `0`s are on the left and all the `1`s are on the right.

---

### Example 2

Input:

```cpp
arr[] = [1, 1]
```

Output:

```cpp
[1, 1]
```

Explanation:

There are no `0`s in the array, so it remains unchanged.

---

## Constraints

```cpp
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 1
```
