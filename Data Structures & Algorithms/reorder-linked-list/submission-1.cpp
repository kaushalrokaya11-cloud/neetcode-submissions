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
    void reorderList(ListNode* head) {
        //Finding middle
        ListNode* slow=head, *fast=head;
        while(fast!=nullptr&& fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }


        //Reversing the second half
        ListNode* curr=slow->next,*prev=nullptr,*nexttemp=nullptr;
        slow->next=nullptr;//ending the first half
        while(curr!=nullptr){
            nexttemp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexttemp;
        }

        // Merging two halves
        ListNode*first=head,*second=prev;
        ListNode*temp1,*temp2;
        while(second!=nullptr){
            temp1=first->next;
            temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }


        
    }
};
