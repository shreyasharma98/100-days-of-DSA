/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
*/
 Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getMeetPoint(ListNode* head){
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* tortoise= head;
        ListNode* hare= head;
        while(hare != NULL && hare->next !=NULL){
            tortoise= tortoise->next;
            hare= hare->next->next;

            if(tortoise== hare){
                return hare;
            }
        }

        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* meetPoint= getMeetPoint(head);
        if(meetPoint == NULL){
            return NULL;
        }
        ListNode* temp= head;
        while(temp != meetPoint){
            temp= temp->next;
            meetPoint= meetPoint->next;
        }
        return temp;
    }

};

