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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater_equal=head, *shift=0, *temp=0;
        int c=2;
        if(head==0 || head->next==0)
            return head;
        if(head->val>=x)
        {
            temp=head;
            c=0;
        }
        else
        {
            while(greater_equal!=0 && greater_equal->next!=0)
            {
                if(greater_equal->next->val>=x)
                    break;
                greater_equal=greater_equal->next;
            }
            temp=greater_equal->next;
        }
        while(temp!=0 && temp->next!=0)
        {
            if(temp->next->val<x)
            {
                c++;
                shift=temp->next;
                temp->next=temp->next->next;
                if(c==1)
                {
                    shift->next=head;
                    greater_equal=head=shift;
                }
                else
                {
                    shift->next=greater_equal->next;
                    greater_equal->next=shift;
                    greater_equal=shift;
                }
                if(temp->next==0)
                    break;
            }
            else
                temp=temp->next;
        }
        return head;
    }
};