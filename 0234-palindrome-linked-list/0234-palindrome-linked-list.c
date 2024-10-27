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
    struct ListNode *slow=head,*fast=head, *h=0, *nh=0;
    int cnt=0,c=1;
    /*while(l!=0)
    {
        cnt++;
        l=l->next;
    }
    l=head;
    while(c<(cnt+1)/2)
    {
        l=l->next;
        c++;
    }*/
    while(fast->next!=0 && fast->next->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    nh=rev(slow->next);
    h=nh;
    //slow->next=h;
    slow=head;
    while(h!=0)
    {
        if(slow->val!=h->val)
        {
            rev(nh);
            return false;
        }
        h=h->next;
        slow=slow->next;
    }
    rev(nh);
    return true;
}
