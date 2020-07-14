# 递归原理

## 344_Reverse_String
因为反转其实就是头尾两元素的交换，所以每一步的idx有明显的递进关系：```idx=idx+1；```
终止条件也很明确：```if(idx == (len/2)) return;```

## 24_Swap_Node_in_Pairs
两两交换节点，并且改变头结点后，不会改变之后节点的状态；
递进关系：```swap(head) = 交换头两个->swap(head->next->next)->链接起来```
终止条件：```if(!head || !head->next) return;```

---

# 递推关系

## 118_Pascal's_Triangle_01
首先，我们定义一个函数```f(i,j)```，它将会返回帕斯卡三角形第 i 行、第 j 列的数字。

我们可以用下面的公式来表示这一递推关系：
```cpp
f(i,j) = f(i−1,j−1) + f(i−1,j)

边界条件为：
if(j==1 || j==i) f(i, j) = 1; 
```
但是这种递归的时间复杂度太高，有很多重复计算。

## 118_Pascal's_Triangle_02
这里因为是生成前n行，所以对于第i行，前面的i-1行就起到了存储计算结果的作用；因此可以直接按坐标去取结果。

## 119_Pascal's_Triangle_II_01
直接返回上一题结果的第k行```return res[rowIndex]```

## 119_Pascal's_Triangle_II_02
要求额外空间为O(k)。可以用一个队列来存上一行，下一行调用完后就出队列，这样需要```O(1+(k-1)+k)=O(2k)=O(k)```的空间复杂度。但显然k比较小时，不满足要求。

## 119_Pascal's_Triangle_II_03
申请一个长度为k的数组，从第二行开始，从右向左根据上一行原地生成当前行的元素。
特别注意：从右向左是因为递推式中，将会用到```row[j-1]```，即其左边的元素，从左到右会生成错误。

## 206_Reverse_Linked_List_01 迭代
三个节点（pre, cur, next),不断反转顺序。

## 206_Reverse_Linked_List_02 递归
假设头结点```head```后面的节点已经反转完成，为新的一段链表```reverseList(head->next)```，那么我们需要做的是
```cpp
head->next->next = head；
head->next = NULL；
```
并返回后一段链表的头结点。

---

# Memorization技术

## 509_Fibonacci_Number
```cpp
F(0) = 0,   F(1) = 1;
F(N) = F(N - 1) + F(N - 2), for N > 1.
```
使用一个```unordered_map```来储存已经计算过的值。

## 70_Climbing_Stairs
要到第n级台阶有两种办法，从第n-1级走一步和从第n-2级走两步；
```cpp
F(0) = 0,   F(1) = 1， F(2) = 2;
F(N) = F(N - 1) + F(N - 2), for N > 2.
```
使用一个```unordered_map```来储存已经计算过的值。