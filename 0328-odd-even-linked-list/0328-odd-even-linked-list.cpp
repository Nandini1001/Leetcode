/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==0 || head->next==0 || head->next->next==nullptr)
            return head;
        /*ListNode *ht=head->next->next, *oh=head, *ot=oh, *eh=head->next, *et=eh;
        while(1)
        {
            ot->next=ht;
            ot=ht;
            if(ht==0)
                et->next=0;
            else
                et->next=ht->next;
            et=et->next;
            if(et==0)
                break;
            ht=ht->next->next;
        }                
        ot=oh;
        while(ot->next!=0)
            ot=ot->next;
        ot->next=eh;
        return oh;*/
       ListNode *odd=head, *evenhead=head->next, *even=evenhead;
       while(even!=nullptr && even->next!=nullptr)
       {
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
       }
       odd->next=evenhead;
       return head;
    }
};