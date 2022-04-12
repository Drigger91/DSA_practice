// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
ListNode* reverseBetween(ListNode* head, int left, int right) {
        //naive-est solution
        vector<int>nums;
        ListNode* left_node = head; 
        for(int i = 1; i < left; i++){
            left_node = left_node->next;
        }
        ListNode* node = left_node;
        for(int i = 0; i <= (right-left); i++){
            nums.push_back(node->val);
            node = node->next;
        }
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            left_node->val = nums[i];
            left_node = left_node->next;
        }
        return head;
        
        
        //actual approach
        
//         if(!head or left==right or head->next==NULL){
//             return head;
//         }
//         ListNode*temp= new ListNode(0);
//         temp->next = head;
//         ListNode*curr = temp;
//         ListNode*prev = NULL;
//         for(int i=0;i<left;i++){
//             prev=curr;
//             curr=curr->next;
//         }
//         ListNode*iter = curr;
//         ListNode* pre_iter = prev;
        
//         //reverse
//         for(int i=left;i<=right;i++){
//             ListNode*forward = iter->next;
//             iter->next = pre_iter;
//             pre_iter = iter;
//             iter = forward;
//         }
//         prev->next = pre_iter;
//         curr->next = iter;
//         return temp->next;
    }