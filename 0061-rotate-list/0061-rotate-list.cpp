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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr|| k==0) return head;
        ListNode *temp=head;
        int cnt=1,c=0;
        while(temp->next)
        {
            cnt++;
            temp=temp->next;
        }
        if(k%cnt==0) return head;
        temp->next=head;
        k=k%cnt;
        temp=head;
        while(temp)
        {
            c++;
            if(cnt-k==c)
                break;
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};