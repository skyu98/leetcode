class Solution { 
    public:
    ListNode* swapPairs(ListNode* head) { 
            if(!head || !head->next) return head;
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            head = tmp;
            head->next->next = swapPairs(head->next->next);
    
            return head;
        }
};
