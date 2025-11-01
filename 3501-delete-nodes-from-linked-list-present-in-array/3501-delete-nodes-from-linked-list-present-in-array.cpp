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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(-1,head);
        ListNode* temp=dummy;
        while(temp->next){
            if(st.count(temp->next->val)){
                deletenode(temp);
            }
            else temp=temp->next;
        }
        return dummy->next;
    }
    void deletenode(ListNode* temp){
        ListNode* dlt=temp->next;
        temp->next=temp->next->next;
        //delete(dlt);
    }
};



//line 27 dont write else runtime error because The test harness will automatically delete all remaining nodes after checking your output. But since you already delete some nodes manually inside your function, the harness doesn’t know that — so it tries to free those nodes again.
//problem in previous is:
// You call find(nums.begin(), nums.end(), value) inside every iteration.
// If nums is large, that gives O(N * M) complexity.
// ✅ Fix: Use an unordered_set<int> for nums to get O(1) average lookup.