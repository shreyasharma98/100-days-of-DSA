/*
Write a program to find the node at which the intersection of two singly linked lists begins.
Example :
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5].
From the head of B, it reads as [5,6,1,8,4,5].
There are 2 nodes before the intersected node in A;
There are 3 nodes before the intersected node in B.
*/
/******

Approach 1: Brute Force
For each node ai in list A, traverse the entire list B and check if any node in list B coincides with ai.
Complexity Analysis
    Time complexity : O(mn)O(mn)O(mn).
    Space complexity : O(1)O(1)O(1).
Approach 2: Hash Table
Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list B: if bi appears in the hash set, then bi is the intersection node.
Complexity Analysis
    Time complexity : O(m+n)O(m+n)O(m+n).
    Space complexity : O(m)O(m)O(m) or O(n)O(n)O(n).
Approach 3: Two Pointers
    Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
    When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
    If at any point pA meets pB, then pA/pB is the intersection node.
    To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pBpBpB to head A, and pApApA to head B, we now ask pBpBpB to travel exactly 2 more nodes than pApApA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
    If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.
Complexity Analysis
    Time complexity : O(m+n)O(m+n)O(m+n).
    Space complexity : O(1)O(1)O(1).
******/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB== NULL){
            return NULL;
        }
        ListNode* Apointer= headA;
        ListNode* Bpointer= headB;

        while(Apointer != Bpointer){
            if(Apointer == NULL)
                Apointer= headB;
            else
                Apointer= Apointer->next;

            if(Bpointer == NULL)
                Bpointer= headA;
            else
                Bpointer= Bpointer->next;
        }
        return Apointer;
    }
};
