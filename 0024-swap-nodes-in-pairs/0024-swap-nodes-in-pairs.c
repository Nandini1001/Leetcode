/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==0 || head->next==0)
        return head;
    struct ListNode *h=head,*g=0,*r=0;
    head=head->next;
    if(h->next->next==0)
    {
        h->next->next=h;
        h->next=0;
        return head;
    }
    while(h!=0)
    {
        g=h->next;
        r=g->next;
        if(g->next==0 || g->next->next==0)
        {
            h->next=g->next;
            g->next=h;
            return head;
        }
        else
        {
            h->next=g->next->next;
            g->next=h;
        }
        h=r;
    }
    return head;
}