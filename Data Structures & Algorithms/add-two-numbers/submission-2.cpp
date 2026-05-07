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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode dummy;
        ListNode *pt=&dummy; 

        while(l1 || l2 || carry){

            int v1= !l1? 0 :l1->val;
            int v2= !l2? 0:l2->val;

            int sum=v1+v2+carry;
            carry=sum/10;
            int value= sum %10;
            

            ListNode *newNode= new ListNode(value);
            pt->next=newNode;
            pt=pt->next;

            l1=!l1?nullptr:l1->next;
            l2=!l2?nullptr:l2->next;
        }
        pt->next=nullptr;
        return dummy.next;

        
    }
};
