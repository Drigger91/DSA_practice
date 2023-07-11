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

//     You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 ListNode* mergeKLists(vector<ListNode*>& lists) {
        //brute force solution
        // if(lists.size()==0){
        //     return NULL;
        // }
        // vector<int>ans;
        // for(int i =0;i<lists.size();i++){
        //     ListNode*temp = lists[i];
        //     while(temp!=NULL){
        //         ans.push_back(temp->val);
        //         temp = temp->next;
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // ListNode*head = new ListNode(0);
        // ListNode*temp = head;
        // for(int i=0;i<ans.size();i++){
        //     ListNode*next = new ListNode(ans[i]);
        //     temp->next = next;
        //     temp=temp->next;
        // }
        // return head->next;
        
        //second approach
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* head = new ListNode(0); 
        ListNode* temp = head; 

        for(ListNode* list : lists){
            if(list) {
                pq.push({list->val, list}); 
            }
        }

        while(!pq.empty()){
            temp->next = pq.top().second; 
            pq.pop(); 
            temp = temp->next; 
            if(temp->next){
                pq.push({temp->next->val, temp->next});
            }
        }

        return head->next;
        
        //can also be done by merging 2 lists consecutively till the array ends (discussion)
    }