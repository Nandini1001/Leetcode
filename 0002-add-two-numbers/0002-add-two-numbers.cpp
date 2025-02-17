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
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        ListNode *h1=l1, *h2=l2;
        int carry=0;
        while(h1!=nullptr || h2!=nullptr)
        {
            int sum=carry;
            if(h1) sum+=h1->val;
            if(h2) sum+=h2->val;
            ListNode *node=new ListNode(sum%10);
            curr->next=node;
            curr=node;
            carry=sum/10;
            if(h1) h1=h1->next;
            if(h2) h2=h2->next;
        }
        if(carry)
        {
            ListNode *node=new ListNode(carry);
            curr->next=node;
            return dummy->next;
        }
        return dummy->next;
    }
};