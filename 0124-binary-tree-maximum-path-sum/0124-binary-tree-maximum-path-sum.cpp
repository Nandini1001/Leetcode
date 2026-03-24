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
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        helper(root, maxsum);
        return maxsum;
    }
    int helper(TreeNode* root, int &maxsum){
        if(root==NULL) return 0;
        int rtsum=max(0,helper(root->right,maxsum));
        int leftsum=max(0,helper(root->left,maxsum));
        maxsum=max(maxsum, rtsum+leftsum+root->val);
        return max(rtsum, leftsum)+root->val;
    }
};