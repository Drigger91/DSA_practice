// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

ListNode* deleteDuplicates(ListNode* head) {
        //map brute force
        while(!head or !head->next){
            return head;
        }
        unordered_map<int,int>m;
        unordered_map<int,int>::iterator it;
        while(head){
            it = m.find(head->val);
            if(it!=m.end()){
                it->second++;
            }
            else{
                m.insert({head->val,1});
            }
            head = head->next;
        }
        vector<int>arr;
        for(auto it:m){
            if(it.second==1){
                arr.push_back(it.first);
            }
        }
        if(arr.size()==0){
            return NULL;
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        ListNode*ans = new ListNode(arr[i]);
        head = ans;
        i++;
        while(i<=arr.size()-1){
            ListNode*next = new ListNode(arr[i]);
            ans->next = next;
            ans = next;
            i++;
        }
        return head;
        
    }