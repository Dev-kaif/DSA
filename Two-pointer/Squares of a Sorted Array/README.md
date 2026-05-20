https://leetcode.com/problems/squares-of-a-sorted-array/description/

# 977. Squares of a Sorted Array

## Problem Statement

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

---

## Example 1

### Input

```txt
nums = [-4,-1,0,3,10]
```

### Output

```txt
[0,1,9,16,100]
```

### Explanation

After squaring:

```txt
[16,1,0,9,100]
```

After sorting:

```txt
[0,1,9,16,100]
```

---

## Example 2

### Input

```txt
nums = [-7,-3,2,3,11]
```

### Output

```txt
[4,9,9,49,121]
```

---

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in non-decreasing order

---

# Follow Up

Squaring each element and then sorting is trivial.

Can you solve it in:

```txt
O(n)
```

using a different approach?

---