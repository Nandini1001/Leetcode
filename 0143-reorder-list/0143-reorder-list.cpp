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
    void reorderList(ListNode* head) {
        if(head->next==nullptr) return;
        ListNode *start=head, *ptr=nullptr, *last=nullptr, *stnxt=nullptr;
        while(true){
            ptr=start;
            while(ptr->next->next!=nullptr)
                ptr=ptr->next;
            last=ptr->next;
            ptr->next=nullptr;
            stnxt=start->next;
            start->next=last;
            last->next=stnxt;
            start=stnxt;
            if(start==nullptr || start->next==nullptr) break;
        }
    }
};