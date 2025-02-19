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
    void rev(ListNode* head)
    {
        ListNode *temp=head, *prevnode=nullptr;
        while(temp)
        {
            ListNode *nextnode=temp->next;
            temp->next=prevnode;
            prevnode=temp;
            temp=nextnode;
        }
    }
    ListNode* kthnode(ListNode* head, int k)
    {
        ListNode* temp=head;
        while(temp)
        {
            k--;
            if(k==0)
                return temp;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* knode, *prevnode=nullptr, *temp=head;
        while(temp)
        {
            knode=kthnode(temp,k);
            if(knode==nullptr)
            {
                if(prevnode) prevnode->next=temp;
                break;
            }
            ListNode *nextnode=knode->next;
            knode->next=nullptr;
            rev(temp);
            if(temp==head)
                head=knode;
            else
                prevnode->next=knode;
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};