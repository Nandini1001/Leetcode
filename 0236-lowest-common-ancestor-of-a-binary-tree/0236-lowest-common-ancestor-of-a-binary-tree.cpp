/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        TreeNode* left=NULL, *rt=NULL;
        if(root->left){
            left=helper(root->left, p, q);
        }
        if(root->right){
            rt=helper(root->right, p, q);
        }
        if(!left && !rt) return (root==p || root==q)?root:NULL;
        if(left && rt) return root;
        if(left) return (root==p || root==q)?root:left;
        if(rt) return (root==p || root==q)?root:rt;
        return NULL;
    }
};