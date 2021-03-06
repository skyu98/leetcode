## 622. Design Circular Queue 01

此题注意几点，为什么我们不用head 和 tail 而非要用 tail和size去推算head呢，这是因为会出现enqueue之后我们只动tail而无head的情况，然后我们去front就会出错，这样需要更多判断。如果只用tail的话我们则不需要太多去考虑维护的。

(tail_ - size_ + k_ + 1) % k_ 加个k_就不存在负数的情况了，很巧妙


## 200. Number of Islands 01 DFS

我们遍历循环，当遇到一个陆地的时候，我们DFS将相连的所有设置成2，然后这样就避免了重复。

这样我们和循环遍历一样，时间复杂度为O(MN), M为行数，N为列数。

空间复杂度最坏的情况为全为陆地，我们需要dfs递归MN次，我们需要的空间复杂度最坏为O(MN)

## 200. Number of Islands 02 BFS

我们一个queue存入一个坐标pair，当我们遇到一个1的时候，则岛屿++，我们广度优先看点是否为相连的1，如果是的话则置0(因为我们需要避免重复)，然后入栈。

时间复杂度为O(MN),空间复杂度，最坏的情况为全为陆地，O(min{M,N})

## 200. Number of Islands 03 UNION FIND

见06_disjointed_set

## 752. Open the Lock 01 BFS

这就是一个BFS的最短路径问题，我们这里设置一个hashmap,先构建出deadends，其实这个映射就是添加一个flag，不可走和经过后的点，那就肯定不是target，我们不必再走回头路，所以每次先判断是否是，如果不是设置为1表示我们走到这了，每次就是8种方式的转锁变换，我们添加入栈作为外围继续前进，每一维就是一个step.

## 279. Perfect Squares 01 BFS

这道题也是很明显的一道最短路径问题，利用BFS模板即可，和752差不多，每次只是去减去一个平方数操作。

## 279. Perfect Squares 02 DP

## 155. Min Stack 01 vector

我们这里简单利用vector来模拟栈

## 155. Min Stack 02 two stack


## 20. Valid Parentheses 01 

我们这里就是遇到左括号push入栈，如果是右括号那就看栈顶是否对应，因为我们"]"这类似情况，空栈访问不了栈顶，我能先PUSH一个#,最后判断是否全部对应出栈，及是不是空栈。

只用遍历一次，所以时间复杂度为O(N)，空间复杂度为O(N)

## 20. Valid Parentheses 02

我们这里遇到左括号，我们就push对应的右括号，如果我们在这个过程中，遇到右括号，但是栈为空，或者栈顶不等于这个右括号，及不对应，则直接false，其他情况就是对应pop。最后我们判断是否完全对应，如果栈为空则为true

时间复杂度为O(N),空间复杂度为O(N)

## 739. Daily Temperatures

我们这里利用一个单调栈，我们存储下标，当当前元素大于栈顶元素的时候(当访问栈顶一定要保证栈不为空)，则计算下标之差存入res的那个位置中，然后循环比较，然后pop，否则的话就存入当前的index。

因为只遍历一次，然后只需维护一个栈，时间复杂度为O(N),空间复杂度为O(N)

## 150. Evaluate Reverse Polish Notation 

知识点:前缀表达式(波兰式) 后缀表达式(逆波兰式)

中缀表达式 : a + b

前缀表达式 : + a b 

后缀表达式 : a b +

- 中转前

1. 每一个表达式用括号括起来

2. 两个表达式中间的运算符提至括号外

for example 

(a+b)*c+d-(e+g)*h

((a+b)*c)+d-((e+g)*h)

(((a+b)*c)+d)-((e+g)*h)

( (((a+b)*c)+d)-((e+g)*h) )

- (((a+b)*c)+d) ((e+g)*h) 

- + ((a+b)*c) d ((e+g)*h)

- + * (a+b) c d ((e+g)*h)

- + * + a b c d ((e+g)*h)

- + * + a b c d * (e+g) h

- + * + a b c d * + e g h

后缀就是往后丢，此处略 ab+c*d+eg+h*-

- 后缀转中缀方法

其实这里用个栈就可以了，遇到数字我们就push进来，遇到op我们就弹出两个值运算再压入。

注意c++ 的 switch必须要一个int，所以比较麻烦，还是都写if else把

这里只需要循环一次，时间复杂度为O(N), 空间复杂度为O(N)

## 133. Clone Graph 01 DFS 递归 数组模拟映射

我们利用题目条件1 <= Node.val <= 100，设置一个100维数组作为int - Node*的映射，克隆图就是一个遍历，如果在数组中存在，那么就是经历过的，否则就new一个点，记录入数组中，他的终止条件是为空则返回空，数组中已有则返回数组中的，neibors递归去push_back其点。

因为只用遍历图一次，所以我们时间复杂度为O(N),空间复杂度为O(N)

## 133. Clone Graph 02 DFS 

原理同上，不过用了unordered_map,更加robust

## 133. Clone Graph 03 BFS 

这里就是套模板装进queue里，这里有一个映射,就是原点到新复制点的映射。如果有value则经历过，跳过，没有则new新的点。

这里因为只需要遍历图一次，所以我们时间复杂度为O(N),空间复杂度为O(N)

## 962_Maximum_Width_Ramp
单调栈。我们抽取出以A[0]为起点的严格递减数列，那么答案的坡底肯定在此序列中。
我们只需要从后往前遍历，当当前元素大于栈顶下标所对应的元素，就说明找到一个坡；
此时开始循环比较，更新res。

时间复杂度：O（n）
空间复杂度：O（n）