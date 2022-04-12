// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list

 ListNode* generate(vector<int> res){
        if(res.size()==0){
            return NULL;
        }
        ListNode*head = new ListNode(res[0]);
        ListNode*temp = head;
        int i = 1;
        while(i<res.size()){
            ListNode*next =  new ListNode(res[i]);
            temp->next = next;
            temp = temp->next;
            i++;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> result;
        while(list1){
            result.push_back(list1->val);
            list1=list1->next;
            
        }
        while(list2){
            result.push_back(list2->val);
            list2=list2->next;
        }
        sort(result.begin(),result.end());
        return generate(result);
    }