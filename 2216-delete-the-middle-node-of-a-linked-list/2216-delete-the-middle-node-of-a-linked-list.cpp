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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slow=head, *fast=head->next->next;
        while(fast!=0 && fast->next!=0)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
        /*ListNode* l=head,*r=head,*f=NULL;
        if(head==NULL || head->next==NULL)
            return NULL;
        int cnt=0,i=1;
        while(l!=0)
        {
            cnt++;
            l=l->next;
        }
        while(i<cnt/2)
        {
            r=r->next;
            i++;
        }
        f=r->next;
        r->next=r->next->next;
        return head;*/
    }
};