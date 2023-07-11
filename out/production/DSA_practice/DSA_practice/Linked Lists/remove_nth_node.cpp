// Given the head of a linked list, remove the nth node from the end of the list and return its head.
#include<bits/stdc++.h>
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp = head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n-1){
            return head->next;
        }
        count = count-n;
        ListNode*temp2 = head;
        while(count){
            temp2=temp2->next;
            count--;
        }
        ListNode* temp3 = temp2->next;
        temp2->next = temp3->next;
        temp3->next = NULL;
        delete temp3;
        return head;
    }