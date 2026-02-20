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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* curhead=head;
        ListNode* prevlast=NULL;
        ListNode* newhead=head;
        ListNode* nextstart=NULL;
        while(1){
            int n=k-1;
            while(n && temp){
                n--;
                temp=temp->next;
            }
            if(!temp){
                if(prevlast)
                    prevlast->next=curhead;
                return newhead;
            }
            nextstart=temp->next;
            temp->next=0;
            temp=nextstart;
            ListNode* khead=reverse(curhead);
            if(curhead==head)
                newhead=khead;
            if(prevlast) prevlast->next=khead;
            prevlast=curhead;
            curhead->next=temp;
            curhead=temp;
        }
        return head;
    }
    ListNode* reverse (ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* next;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};