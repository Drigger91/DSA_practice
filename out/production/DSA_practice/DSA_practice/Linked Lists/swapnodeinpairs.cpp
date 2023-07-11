// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode*curr = head;
        ListNode*prev = NULL; //it is important to declare them as null
        ListNode*next = NULL;
        int count = 0;
        while(curr!=NULL and count<2){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head->next = swapPairs(next);
        return prev;
    }