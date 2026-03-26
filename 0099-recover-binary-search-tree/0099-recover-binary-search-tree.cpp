/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL, *second=NULL;
        TreeNode * prev=new TreeNode(INT_MIN);
        helper(prev, root, first, second);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
    void helper(TreeNode*& prev, TreeNode* curr, TreeNode*& first, TreeNode*& second){
        if(curr==NULL) return;
        helper(prev, curr->left, first, second);
        if(prev->val>curr->val){
            if(first==NULL) first=prev;
            second=curr;
        }
        prev=curr;
        helper(prev, curr->right, first, second);
    }
};