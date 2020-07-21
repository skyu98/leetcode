# 递归原理

## 344_Reverse_String_01 递归
因为反转其实就是头尾两元素的交换，所以每一步的idx有明显的递进关系：```idx=idx+1；```
终止条件也很明确：```if(idx == (len/2)) return;```
时间复杂度O(n)，交换了n/2次；
空间复杂度O(n)，使用了O(n)的堆栈空间。

## 344_Reverse_String_02 双指针迭代
思想相同，用循环代替递归调用。
时间复杂度O(n)，交换了n/2次；
空间复杂度O(1)，使用了常量级的堆栈空间。

## 24_Swap_Node_in_Pairs
两两交换节点，并且改变头结点后，不会改变之后节点的状态；
递进关系：```swap(head) = 交换头两个->swap(head->next->next)->链接起来```
终止条件：```if(!head || !head->next) return;```
时间复杂度O(n)，交换了n/2次，访问了n个节点；
空间复杂度O(n)，使用了O(n)的堆栈空间。
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
时间复杂度：$O(numRows^3)$:
很明显外层循环需要运行numRows次，但在外层循环的每次迭代中，内层
循环要运行rowNum次，每次还要递归去取得相应的值。因此，triangle 发生的更新总数为$1^2 + 2^2 + 3^2 + \ldots + numRows^2$，根据高斯公式有$(n(n+1)(2n+1))/6 = O(numRows^3)$

空间复杂度：$O(numRows^3)$。要储存每次得到的值。

## 118_Pascal's_Triangle_02
这里因为是生成前n行，所以对于第i行，前面的i-1行就起到了存储计算结果的作用；因此可以直接按坐标去取结果。
时间复杂度：$O(numRows^2)$:
很明显外层循环需要运行numRows次，但在外层循环的每次迭代中，内层
循环要运行rowNum次。因此，triangle 发生的更新总数为$1 + 2 + 3 + \ldots + numRows$，根据高斯公式有$(numRows*(numRows + 1))/2 = O(numRows^2)$

空间复杂度：$O(numRows^2)$。要储存每次得到的值。

## 119_Pascal's_Triangle_II_01
直接返回上一题结果的第k行```return res[rowIndex]```
时间复杂度：$O(rowIndex^2)$；
空间复杂度：$O(rowIndex^2)$。要储存每次得到的值。

## 119_Pascal's_Triangle_II_02
要求额外空间为O(k)。可以用一个队列来存上一行，下一行调用完后就出队列，这样需要```O(1+(k-1)+k)=O(2k)=O(k)```的空间复杂度。但显然k比较小时，不满足要求。
时间复杂度：$O(rowIndex^2)$。

## 119_Pascal's_Triangle_II_03
申请一个长度为k的数组，从第二行开始，从右向左根据上一行原地生成当前行的元素。
特别注意：从右向左是因为递推式中，将会用到```row[j-1]```，即其左边的元素，从左到右会生成错误。
时间复杂度：$O(rowIndex^2)$；
空间复杂度：$O(rowIndex)$。只需要一个K大的数组。

## 206_Reverse_Linked_List_01 迭代
三个节点（pre, cur, next),不断反转顺序。
时间复杂度O(n)，空间复杂度O(1)。

## 206_Reverse_Linked_List_02 递归
假设头结点```head```后面的节点已经反转完成，为新的一段链表```reverseList(head->next)```，那么我们需要做的是
```cpp
head->next->next = head；
head->next = NULL；
```
并返回后一段链表的头结点。
时间复杂度O(n)，空间复杂度O(n)。

---

# Memorization技术

## 509_Fibonacci_Number
```cpp
F(0) = 0,   F(1) = 1;
F(N) = F(N - 1) + F(N - 2), for N > 1.
```
使用一个```unordered_map```来储存已经计算过的值。
每个数字访问一次，时间复杂度O(N)；
每个数字都需要储存，空间复杂度O(N)。

## 70_Climbing_Stairs
要到第n级台阶有两种办法，从第n-1级走一步和从第n-2级走两步；
```cpp
F(0) = 0,   F(1) = 1， F(2) = 2;
F(N) = F(N - 1) + F(N - 2), for N > 2.
```
使用一个```unordered_map```来储存已经计算过的值。
每个台阶访问一次，时间复杂度O(N)；
每个台阶都需要储存，空间复杂度O(N)。

---

# 复杂度分析（见算法笔记——递归）
## 时间复杂度
## 空间复杂度
## 尾递归

## 104. Maximum Depth of Binary Tree 01 递归(迭代见structure/tree)
* 在树的递归算法中，“自顶向下”指的是通过给函数传参的方式让信息流从根结点向下走，从而求得最终结果的过程。

递归这里就很巧妙，递归就是一直递到下一层然后不断+1上来，然后回溯上去得到值，这里我们需要比较左右子树的最大值。
时间复杂度O(N)，要访问每个节点；
空间复杂度最坏O(N)，最好O(logN)。

## 104. Maximum Depth of Binary Tree 03 DFS 递归(迭代见structure/tree)
* 在树的递归算法中，“自底向上”指的是通过函数返回值让信息流从叶结点向上走，从而求得最终结果的过程。
这其实就是刚才讲的自顶向下的方法。
时间复杂度O(N)，要访问每个节点；
空间复杂度最坏O(N)，最好O(logN)。

## 50_Pow(x,n)_01 暴力递归
暴力运算，每次递归pow（x, n-1）。
时间复杂度为$O(n)$；空间复杂度O(n)，会导致堆栈溢出。
改为尾递归，也会超出时间限制。

## 50_Pow(x,n)_02 递归快速幂
当有了```half = pow(x, n/2)```, ```pow(x, n) = (n%2) == 0 ? half * half : half * half * x;``` 
时间复杂度为$O(logn)$；空间复杂度$O(logn)$。

## 779_K-th_Symbol_in_Grammar
明显结构是：前半部分与上一行相同，后一部分是上一行反转；
所以，假设已经知道第N-1行，那么：
```cpp
// 前半部分
if(K <= mid): kthGrammar(N, K) = kthGrammar(N-1, K);
// 后半部分
else:         kthGrammar(N, K) =  1-kthGrammar(N-1, K-mid);
```
时间复杂度O(N)，空间复杂度O(1)。

## 95_Unique_Binary_Search_Trees_II
我们知道```generate(int start，int end)```是用于生成$[start, end]$区间所有的二叉搜索树，那么对于其中的某个位置产生的根节点i，```left = generate(start，i-1)```即是它所有可能的左子树；同理，```right = generate(i+1, end)```即是它所有可能的右子树。
因此，我们只需要遍历left和right中的子树，生成所有可能的组合并储存，再处理下一个根节点(i+1)即可。

时间复杂度：生成一棵二叉搜索树需要O(n)的时间复杂度，一共有$G_n$棵二叉搜索树，也就是$O(n*G_n)$。而卡特兰数以 $\frac{4^n}{n^{3/2}}$增长，因此总时间复杂度为 $O(\frac{4^n}{n^{1/2}})$。

空间复杂度：n个点生成的二叉搜索树有$G_n$棵，每棵树有n个节点，因此存储空间为$O(n*G_n) = (\frac{4^n}{n^{1/2}})$。递归函数有O(n)的递归栈。

