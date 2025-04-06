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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> nodesqu;
        nodesqu.push(root);
        bool lefttort=true;
        while(!nodesqu.empty()){
            int n=nodesqu.size();
            vector<int> row(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node=nodesqu.front();
                nodesqu.pop();
                int ind=(lefttort)?i:n-1-i;
                row[ind]=node->val;
                if(node->left)
                    nodesqu.push(node->left);
                if(node->right)
                    nodesqu.push(node->right);
            }
            lefttort=!lefttort;
            res.push_back(row);
        }
        return res;
    }
};