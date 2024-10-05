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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* l=head,*f=head;
        if(head==NULL)
            return head;
        while(1)
        {int c=0;
        if(l->val==val && l->next!=0)
        {
                l=l->next;
                head=head->next;
                c=1;
                //free(f);
                //return ;
        }
        if(c==0)
        break;
        }
        while(l->next!=0)
        {
            if(l->next->val==val)
            {
                f=l->next;
                l->next=l->next->next;
            }
            else
                l=l->next;
        }
        if(l->val==val)
        {
                l=l->next;
                return l;
        }
        return head;
    }
};