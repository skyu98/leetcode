# 图的一些重要题目或者算法

# 单向图——拓扑排序
## **拓扑排序：如果对于有向图中存在的任意一条u->v的边，排序中u都在v的前面，那么这样的排序是拓扑排序**。

## 210_Course_Schedule_II
此题就是纯粹的拓扑排序框架。

### DFS:
对于图中的任意一个节点，它在搜索的过程中有三种状态，即：

* 「未搜索」：我们还没有搜索到这个节点；

* 「搜索中」：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；

* 「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的更底部的位置，满足拓扑排序的要求。

通过上述的三种状态，我们就可以给出使用深度优先搜索得到拓扑排序的算法流程，在每一轮的搜索搜索开始时，我们任取一个「未搜索」的节点开始进行深度优先搜索。

我们将当前搜索的节点 u 标记为「搜索中」，遍历该节点的每一个相邻节点 v：

* 如果 v 为「未搜索」，那么我们开始搜索 v，待搜索完成回溯到 u；

* 如果 v 为「搜索中」，那么我们就找到了图中的一个环，因此是不存在拓扑排序的；

* 如果 v 为「已完成」，那么说明 v 已经在栈中了，而 u 还不在栈中，因此 u 无论何时入栈都不会影响到(u,v)之间的拓扑关系，因此不用进行任何操作。

当 u 的所有相邻节点都为「已完成」时，我们将 u 放入栈中，并将其标记为「已完成」。

在整个深度优先搜索的过程结束后，如果我们没有找到图中的环，那么栈中存储这所有的 n 个节点，从栈顶到栈底的顺序即为一种拓扑排序。

### BFS：
我们考虑拓扑排序中最前面的节点，该节点一定不会有任何入边。当我们将一个节点加入答案中后，我们就可以移除它的所有出边。如果某个相邻节点变成了「没有任何入边的节点」，那么就代表着这个节点是最前面的节点了。按照这样的流程，我们不断地将没有入边的节点加入答案，直到答案中包含所有的节点（得到了一种拓扑排序）或者不存在没有入边的节点（图中包含环）。

算法

我们使用一个队列来进行广度优先搜索。开始时，所有入度为 0 的节点都被放入队列中，它们就是可以作为拓扑排序最前面的节点，并且它们之间的相对顺序是无关紧要的。

在广度优先搜索的每一步中，我们取出队首的节点 u：

我们将 u 放入答案中；

我们移除 u 的所有出边，也就是将 u 的所有相邻节点的入度减少 1。如果某个相邻节点 v 的入度变为 0，那么我们就将 v 放入队列中。

在广度优先搜索的过程结束后。如果答案中包含了这 n 个节点，那么我们就找到了一种拓扑排序，否则说明图中存在环，也就不存在拓扑排序了。

时间复杂度：$O(n+m)$，其中n为点数，m为边数。

## 1203_Sort_Items_by_Groups_Respecting_Dependencies
此题既然涉及到先后顺序，则说明是有向图，排序则为拓扑排序。由于每个组的任务在结果中是在一起的，则说明组间也是有先后顺序的。因此，根据对每个任务curItem，给出的顺序要求beforeItem，我们需要进行下面两个步骤：
* 1.遍历beforeItem，如果其中的任务item是当前组的，则建立组内关系（有item->curItem的边）
* 2.如果其中的任务item不是当前组的，则建立组间关系（有group[item]->group[curItem]的边。

建立好组间和组内两张有向图后，我们则先对组间进行拓扑排序，再依次在组内进行拓扑排序。

* 时间复杂度：拓扑排序就是就是在图中进行一次广度优先遍历，时间复杂度为图的顶点数加边数，假设当前问题的图结构的顶点数为 V、边数为 E，可以简记时间复杂度为 $O(V+E)$。

* 空间复杂度：假设当前问题的图结构的顶点数为 V、边数为 E，可以简记时间复杂度为 $O(V+E)$。



