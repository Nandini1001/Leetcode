/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow=NULL, *fast=NULL, *p=head;
    int cnt=0;
    if(head==NULL)
        return head;
    if(head->next==0)
        return head;
    if(head->next->next==0)
    {
        p=head->next;
        return p;
    }
    slow=fast=head;
    while(1)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast->next==0 || fast->next->next==0)
            break;
    }
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    if(cnt%2==0)
    {
        fast=slow->next;
        return fast;
    }    
    else
        return slow;
}
