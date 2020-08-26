/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
*/
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
    int length(ListNode* head){
        ListNode* temp= head;
        int len= 0;
        while(temp != NULL){
            temp= temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if((!head) || (!head->next) || (k==0))
            return head;
        ListNode* temp= head;
        int len= length(head);
        k= k% len;
        if(k==0){
            return head;
        }
        for(int i=0; i<len-k-1; i++){
            temp= temp->next;
        }
        ListNode* tail2= temp;
        ListNode* newHead= temp->next;
        temp= temp->next;
        tail2->next= NULL;
        while(temp->next != NULL)
            temp= temp->next;
        temp->next= head;
        return newHead;
    }
};
