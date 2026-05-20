https://leetcode.com/problems/remove-duplicates-from-sorted-array/

# 26. Remove Duplicates from Sorted Array

## Problem Statement

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.

The relative order of the elements should be kept the same.

Consider the number of unique elements in `nums` to be `k`.

After removing the duplicates, return `k`.

The first `k` elements of `nums` should contain the unique elements in sorted order.

The remaining elements beyond index `k - 1` do not matter.

---

## Custom Judge

The judge will test your solution with the following code:

```cpp
int[] nums = [...];
int[] expectedNums = [...];

int k = removeDuplicates(nums);

assert k == expectedNums.length;

for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, your solution will be accepted.

---

## Example 1

### Input

```txt
nums = [1,1,2]
```

### Output

```txt
2
```

### Modified Array

```txt
[1,2,_]
```

### Explanation

Your function should return `k = 2`, with the first two elements of `nums` being:

```txt
1 2
```

It does not matter what remains beyond `k`.

---

## Example 2

### Input

```txt
nums = [0,0,1,1,1,2,2,3,3,4]
```

### Output

```txt
5
```

### Modified Array

```txt
[0,1,2,3,4,_,_,_,_,_]
```