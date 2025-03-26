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
private:
    void preorder(TreeNode* root, vector<int>& arr)
    {
        if(root==nullptr)
            return;
        /*arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);*/
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* top=s.top();
            s.pop();
            arr.push_back(top->val);
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root,arr);
        return arr;
    }
};