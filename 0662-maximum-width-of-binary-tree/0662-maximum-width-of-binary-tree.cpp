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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxwidth=INT_MIN;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long min=q.front().second, last;
            while(size){
                long long i=q.front().second;
                TreeNode*node=q.front().first;
                q.pop();
                last=i;
                if(node->left) q.push({node->left, 2*(i-min)+1});
                if(node->right) q.push({node->right, 2*(i-min)+2});
                size--;
            }
            maxwidth=max(maxwidth,last-min+1);
        }
        return (int)maxwidth;
    }
};