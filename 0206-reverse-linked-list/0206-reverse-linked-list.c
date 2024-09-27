/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p=head,*s=NULL,*q=NULL;
    if(head==NULL)
        return head;
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