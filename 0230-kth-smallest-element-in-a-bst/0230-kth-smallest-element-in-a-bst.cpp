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
    int kthSmallest(TreeNode* root, int k) {
        int ksmall=-1;
        int cnt=1;
        helper(root,&ksmall,&cnt,k);
        return ksmall;
    }
    void helper(TreeNode *root, int *ksmall, int* cnt, int k){
        if(root==NULL) return;
        helper(root->left,ksmall,cnt,k);
        if(*cnt==k){
            *ksmall=root->val;
            (*cnt)++;
            return;
        }
        (*cnt)++;
        helper(root->right,ksmall,cnt,k);
    }
};