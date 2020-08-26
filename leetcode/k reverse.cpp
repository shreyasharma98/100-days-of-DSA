/*Given a linked list,
reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        int len=0;
        while(temp!= NULL){
            temp= temp->next;
            len++;
        }
        return reverse(head, k, len);
    }
    ListNode* reverse(ListNode* head, int k, int len){
        if(len < k)
            return head;
        ListNode* curr= head;
        ListNode* h2= NULL;
        ListNode* prev= NULL;
        int count= 0;
        while(curr!=NULL && count< k){
            h2= curr->next;
            curr->next= prev;
            prev= curr;
            curr= h2;
            count++;
        }
        if(h2 !=NULL){
            head->next= reverse(h2, k, len- k);
        }
        return prev;
    }
};
