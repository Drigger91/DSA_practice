// Given the head of a linked list, rotate the list to the right by k places.

 ListNode*generateList(vector<int> result){
        ListNode* head = new ListNode(result[0]);
        ListNode*temp = head;
        for(int i=1;i<result.size();i++){
            ListNode *next = new ListNode(result[i]);
            temp->next = next;
            temp = temp->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> ans;
        if(!head or !head->next){
            return head;
        }
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        vector<int> result;
        result = ans;
        for(int i=0;i<ans.size();i++){
            result[(i+k)%ans.size()] = ans[i];
        }
        head = generateList(result);
        return head;
    }