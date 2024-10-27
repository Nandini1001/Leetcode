/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* rev(struct ListNode *head)
{
    struct ListNode *p,*q,*s;
    p=head;
    q=head->next;
    while(q!=NULL)
    {
        s=q->next;
        q->next=p;
        p=q;
        q=s;
    }
    head->next=NULL;
    head=p;
    return head;
}
bool isPalindrome(struct ListNode* head) {
    if(head==0 || head->next==0)
        return true;
    struct ListNode *l=head,*h=0;
    int cnt=0,c=1;
    while(l!=0)
    {
        cnt++;
        l=l->next;
    }
    l=head;
    while(c<(cnt+1)/2)
    {
        l=l->next;
        c++;
    }
    h=rev(l->next);
    l->next=h;
    l=head;
    while(h!=0)
    {
        if(l->val!=h->val)
        {
            return false;
        }
        h=h->next;
        l=l->next;
    }
    return true;
}
