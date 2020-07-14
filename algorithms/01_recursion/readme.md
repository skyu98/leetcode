# 递归原理

## 344_Reverse_String
因为反转其实就是头尾两元素的交换，所以每一步的idx有明显的递进关系：idx=idx+1；
终止条件也很明确：到中间元素时，return。

## 24_Swap_Node_in_Pairs
两两交换节点，并且改变头结点后，不会改变之后节点的状态；
递进关系：swap(head) = 交换头两个->swap(head->next->next)->链接起来
终止条件：if(!head || !head->next) return;

# 递推关系
