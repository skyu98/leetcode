# 二分查找

## 核心思想：通过nums[mid]和target之间的关系，来确定target所在区间。

## 704_Binary_Search_01 迭代
最基础的二分查找。
时间复杂度O(logN)，空间复杂度O(1)。

## 704_Binary_Search_02 递归
换个写法。
时间复杂度O(logN)，空间复杂度O(1)。

## 69_Sqrt(x)
判断条件改变：```if(mid*mid == x)```。重点是在于精确度的处理。
时间复杂度O(logX)， 空间复杂度O(1)。

## 374_Guess_Number_Higher_or_Lower_01 二分查找
和最基础的一样，用接口来判断而已。
时间复杂度O(logN)，空间复杂度O(1)。

## 374_Guess_Number_Higher_or_Lower_02 三分查找
思想和二分查找一样，通过比较分界点来判断区间。
时间复杂度$O(log_3N)$，空间复杂度O(1)。
**为什么三分查找复杂度更低，但是更经常用二分查找？**
最坏情况下三分查找比较次数比二分查找最坏情况要多。

## 33_Search_in_Rotated_Sorted_Array
这种情况虽然复杂一点，但是核心思想没有变：**通过nums[mid]和target之间的关系，来确定target所在区间。**
只是要特别注意，还要通过比较nums[mid]和边界值，来确定target是否和mid在同一有序区间。
时间复杂度O(logN)，空间复杂度O(1)。