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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==0 || head->next==0)
            return head;
        ListNode *temp=head, *n=head->next, *f=0;
        while(n!=0)
        {
            if(temp->val==n->val)
            {
                f=temp->next;
                temp->next=n->next;
                n=n->next;
                //free(f);
            }
            else
            {
                temp=n;
                n=n->next;
            }
        }
        return head;
    }
};