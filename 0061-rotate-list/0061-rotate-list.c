/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *t=head,*tail=head;
    int c=1,cnt=0;
    if(head==0 || head->next==0)
        return head;
    while(t!=0)
    {
        cnt++;
        t=t->next;
    }
    k=k%cnt;
    while(c<(cnt-k))
    {
        c++;
        tail=tail->next;
    }
    t=tail;
    while(t->next!=0)
        t=t->next;
    t->next=head;
    head=tail->next;
    tail->next=0;
    // while(head!=0)
    // {
    //     printf("%d ",head->val);
    //     head=head->next;
    // }
    return head;
}