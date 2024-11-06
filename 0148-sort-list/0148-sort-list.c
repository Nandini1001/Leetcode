/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middle(struct ListNode *head)
{
    struct ListNode *slow=head,*fast=head->next;
    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
struct ListNode* merge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *temp=dummy;
    while(list1!=0 && list2!=0)
    {
        if(list1->val>list2->val)
        {
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
        else
        {
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
    }
    if(list1!=0)
        temp->next=list1;
    if(list2!=0)
        temp->next=list2;
    return dummy->next;
}
struct ListNode* sortList(struct ListNode* head) {
    if(head==0 || head->next==0)
        return head;
    struct ListNode *mid=middle(head);
    struct ListNode *right=mid->next, *left=head;
    mid->next=0;
    left=sortList(left);
    right=sortList(right);
    return merge(left,right);
}