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
    vector<int> inorderTraversal(TreeNode* root) {
        //morris traversal
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* leftrtmost=curr->left;
                while(leftrtmost->right && leftrtmost->right!=curr){
                    leftrtmost=leftrtmost->right;
                }
                if(leftrtmost->right==NULL){
                    leftrtmost->right=curr;
                    curr=curr->left;
                }
                else{
                    leftrtmost->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};