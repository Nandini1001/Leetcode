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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*ListNode *r=head,*l=head;
        if(head==NULL)
            return NULL;
        int i=1,cnt=0;
        while(r!=0)
        {
            cnt++;
            r=r->next;
        }
        r=head;
        if(n==cnt)
            return r->next;
        while(i<=n)
        {
            r=r->next;
            i++;
        }
        while(r->next!=NULL)
        {
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        l=l->next;
        return head;*/
        if(head==nullptr) return head;
        ListNode *fast=head;
        while(fast)
        {
            fast=fast->next;
            n--;
            if(n==0) break;
        }
        if(fast==nullptr)
        {
            ListNode *newhead=head->next;
            delete (head);
            return newhead;
        }
        ListNode *slow=head;
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *dltnode=slow->next;
        slow->next=slow->next->next;
        delete (dltnode);
        return head;
    }
};