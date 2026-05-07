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
        Node* header=head;
         vector<Node*>newNodeAddresses;
         unordered_map<Node*,int> addressToIndex;
         unordered_map<int,Node*> indexToAddress;

         if(!head){return head;}
        
        int i=0;
        while(header){
            int value=header->val;
            Node* node= new Node(value);
            // node->val=header->val;
            newNodeAddresses.push_back(node);
            addressToIndex[header]=i;
            indexToAddress[i]=header->random;
            i++;
            header=header->next;
        }
        addressToIndex[nullptr]=i;
        newNodeAddresses.push_back(nullptr);
        header=head;
        i=0;
        Node *newHead=newNodeAddresses[i];
      
        
        while(newHead){
            newHead->val=header->val;
            newHead->next=newNodeAddresses[i+1];
            // newHead->random=newNodeAddresses[addressToIndex[header]];
            int randomPointerIndex=addressToIndex[indexToAddress[i]];
            newHead->random=newNodeAddresses[randomPointerIndex];
            header=header->next;
            newHead=newHead->next;
            i++;

        }
        return newNodeAddresses[0];
        
    }
};
