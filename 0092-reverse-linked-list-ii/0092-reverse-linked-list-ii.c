/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *leftt=head, *rightt=head;
    int c=1;
    while(c!=left)
    {
        c++;
        leftt=leftt->next;
    }
       // leftt=leftt->next;
       c=1;
    while(c!=right)
    {
        c++;
        rightt=rightt->next;
    }
       // rightt=rightt->next;
    if(leftt==0)
        return head;
    struct ListNode *p=leftt,*s=NULL,*q=leftt->next, *temp=head;
    if(head==NULL || head->next==0 || leftt==rightt)
        return head;
    while(leftt!=head && temp->next!=leftt)
        temp=temp->next;
    //q=leftt->next;
    while(p!=rightt)
    {
        s=q->next;
        q->next=p;
        p=q;
        q=s;
    }
    leftt->next=s;
    if(leftt==head)
        return rightt;
    temp->next=rightt;
    return head;
}