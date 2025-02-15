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
private:
    ListNode* reverse(ListNode *head)
    {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *newhead=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *midhead=reverse(slow->next);
        ListNode *backhead=midhead;
        ListNode *frthead=head;
        while(backhead)
        {
            if(frthead->val!=backhead->val)
            {
                reverse(midhead);
                return false;
            }
            frthead=frthead->next;
            backhead=backhead->next;
        }
        reverse(midhead);
        return true;

    }
};