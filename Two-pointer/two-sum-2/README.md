https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

# 167. Two Sum II - Input Array Is Sorted

## Solved **Medium**

### Topics
- Array
- Two Pointers
- Binary Search

---

Given a **1-indexed** array of integers `numbers` that is already sorted in **non-decreasing order**, find two numbers such that they add up to a specific `target` number.

Let these two numbers be:

```txt
numbers[index1] and numbers[index2]
````

where:

```txt
1 <= index1 < index2 <= numbers.length
```

Return the indices of the two numbers:

```txt
[index1, index2]
```

of length `2`.

The tests are generated such that there is **exactly one solution**.

You may **not** use the same element twice.

Your solution must use only:

```txt
constant extra space
```

---

# Example 1

## Input

```txt
numbers = [2,7,11,15]
target = 9
```

## Output

```txt
[1,2]
```

## Explanation

```txt
2 + 7 = 9
```

Therefore:

```txt
index1 = 1
index2 = 2
```

We return:

```txt
[1,2]
```

---

# Example 2

## Input

```txt
numbers = [2,3,4]
target = 6
```

## Output

```txt
[1,3]
```

## Explanation

```txt
2 + 4 = 6
```

Therefore:

```txt
index1 = 1
index2 = 3
```

We return:

```txt
[1,3]
```

---

# Example 3

## Input

```txt
numbers = [-1,0]
target = -1
```

## Output

```txt
[1,2]
```

## Explanation

```txt
-1 + 0 = -1
```

Therefore:

```txt
index1 = 1
index2 = 2
```

We return:

```txt
[1,2]
```

---

# Constraints

```txt
2 <= numbers.length <= 3 * 10^4

-1000 <= numbers[i] <= 1000

numbers is sorted in non-decreasing order.

-1000 <= target <= 1000

The tests are generated such that there is exactly one solution.
```