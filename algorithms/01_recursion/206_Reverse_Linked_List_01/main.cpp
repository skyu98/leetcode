class solution{
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* cur = head, *nxt = head, *pre = NULL;
        while(cur)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};