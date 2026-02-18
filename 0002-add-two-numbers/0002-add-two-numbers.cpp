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
        ListNode* newhead= new ListNode(-1);
        ListNode* node=newhead;
        int carry=0;
        while(l1 && l2){
            ListNode* temp= new ListNode();
            node->next=temp;
            node=temp;
            int sum=l1->val+l2->val+carry;
            if(sum>=10){
                node->val=sum%10;
                carry=1;
            }
            else{
                node->val=sum;
                carry=0;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            ListNode* temp= new ListNode();
            node->next=temp;
            node=temp;
            int sum=l1->val+carry;
            if(sum>=10){
                node->val=sum%10;
                carry=1;
            }
            else{
                node->val=sum;
                carry=0;
            }
            l1=l1->next;
        } 
        while(l2){
            ListNode* temp= new ListNode();
            node->next=temp;
            node=temp;
            int sum=l2->val+carry;
            if(sum>=10){
                node->val=sum%10;
                carry=1;
            }
            else{
                node->val=sum;
                carry=0;
            }
            l2=l2->next;
        }
        if(carry){
            ListNode* temp= new ListNode(1);
            node->next=temp;
        }
        return newhead->next;
    }
};