// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed

 ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next){
            return head;
        }
        ListNode*temp = head;
        int count = 0;
        while(temp->next){
            count++;
            temp = temp->next; 
        }
        if(count<k-1){
            return head;
        }
        ListNode*curr = head;
        ListNode*prev = NULL; //it is important to declare them as null
        ListNode*next = NULL;
        count = 0;
        while(curr!=NULL and count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head->next=reverseKGroup(next,k);
        return prev;
        
    }