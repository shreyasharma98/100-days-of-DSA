/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
Example :
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //linear time, linear space complexity
        if(!head)
            return NULL;
        unordered_map<Node*, Node*> map;
        Node* newHead= new Node(head->val);
        Node* tail= newHead;
        map[head]= newHead;
        Node* temp= head->next;
        while(temp){  //just clone nodes w/o random pointer, just nodes
            tail->next= new Node(temp->val);
            tail= tail->next;
            map[temp]= tail;
            temp= temp->next;
        }
        temp= head;
        Node* ptr= newHead;
        while(temp){  //2nd pass for copying random pointer
            if(temp->random)
                ptr->random= map[temp->random];
            else
                ptr->random= NULL;
            ptr= ptr->next;
            temp= temp->next;
        }
        return newHead;
    }
};
