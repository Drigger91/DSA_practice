#include<bits/stdc++.h>

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //integer out of range 
    // ListNode* makeList(int n){
    //     ListNode*head = new ListNode(0);
    //     ListNode*temp = head;
    //     while(n){
    //         int digit = n%10;
    //         ListNode*next = new ListNode(digit);
    //         n = n/10;
    //         temp->next=next;
    //         temp=temp->next;
    //     }
    //     return head->next;
    // }
    ListNode* reverse(ListNode* head){
        ListNode* curr= head;
        ListNode*prev = NULL;
        while(curr!=NULL){
            ListNode*next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode*head = new ListNode(0);
        ListNode*temp = head;
        int carry = 0;
        while(list1!=NULL and list2!=NULL){
            int digit = list1->val+list2->val+carry;
            carry = digit/10;
            if(carry!=0){
                digit = digit-10;
            }
            ListNode*next = new ListNode(digit);
            temp->next=next;
            temp=temp->next;
            list1=list1->next;
            list2=list2->next;
        }
        while(list1){
            int digit = list1->val+carry;
            carry = digit/10;
            if(carry!=0){
                digit = digit-10;
            }
            ListNode*next = new ListNode(digit);
            temp->next=next;
            temp=temp->next;
            list1=list1->next;
        }
        while(list2){
            int digit = list2->val+carry;
            carry = digit/10;
            if(carry!=0){
                digit = digit-10;
            }
            ListNode*next = new ListNode(digit);
            temp->next=next;
            temp=temp->next;
            list2=list2->next;
        }
        if(carry){
            ListNode*next = new ListNode(carry);
            temp->next=next;
        }
        return head->next;
        
    }
;
};