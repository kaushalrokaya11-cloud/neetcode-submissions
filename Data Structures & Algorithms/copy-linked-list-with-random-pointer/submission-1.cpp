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
        if(!head){return head;}
        unordered_map<Node*,Node*> hmap;

        Node* curr=head;
        
        while(curr){
            Node* node= new Node(curr->val);
            hmap[curr]=node;
            curr=curr->next;

        }
        hmap[nullptr]=nullptr;
        Node* list1=head;
       Node* list2=hmap[list1];

        while(list1){
            list2->next=hmap[list1->next];
            list2->random=hmap[list1->random];
            list1=list1->next;
            list2=list2->next;
        }
        
        return hmap[head];
    }
};
