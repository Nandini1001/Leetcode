/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *h1=list1,*h2=list2,*r=NULL,*rr=NULL;
    if(list1==NULL && list2==NULL)
        return rr;
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(h1->val>h2->val)
    {
        rr=list2;
        r=list2;
        h2=h2->next;
        //r->next=h1;
        //h1=h1->next;
        //r=r->next;
    }
    else
    {
        rr=list1;
        r=list1;
        h1=h1->next;
        //r->next=h2;
        //h2=h2->next;
        //r=r->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->val<h2->val)
        {
            r->next=h1;
            h1=h1->next;
            r=r->next;
        }
        else if(h1->val>h2->val)
        {
            r->next=h2;
            h2=h2->next;
            r=r->next;
        }
        else
        {
            r->next=h2;
            h2=h2->next;
            r=r->next;
            r->next=h1;
            h1=h1->next;
            r=r->next;
        }
    }
    if(h1!=NULL)
    {
        r->next=h1;
        //h1=h1->next;
    }
    if(h2!=NULL)
    {
        r->next=h2;
        //h2=h2->next;
    }
    return rr;

}