/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==0 || head->next==0)
            return head;
    struct ListNode *h=0,*new=0,*prev=head,*nxt=head->next;
        if(head->val!=head->next->val)
        {   h=new=head;
            prev=nxt;
            nxt=nxt->next;
        }        
        int c=0;
        while(nxt!=0)
        {
            if(c==0)
            {
                if(prev->val!=nxt->val)
                {
                    if(h==0)
                    {
                        h=new=prev;
                        h->next=0;
                    }
                    else
                    {
                        new->next=prev;
                        new=prev;
                    }
                    prev=nxt;
                    nxt=nxt->next;
                }
                else
                    c=1;
            }
            else
            {
                if(prev->val!=nxt->val)
                {
                    c=0;
                    prev=nxt;
                    nxt=nxt->next;
                }
                else
                    nxt=nxt->next;
            }
        }
        if(c==0 && h==0)
        {
            h=prev;
            h->next=0;
        }
        else if(h!=0 && c==0)
        {
            new->next=prev;
            new->next->next=0;
        }
        else if(h!=0 && c==1)
            new->next=0;
        return h;
}