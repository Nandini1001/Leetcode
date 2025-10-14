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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track);
        unordered_map<TreeNode*, bool> vis;
        helper(target,parent_track,vis,0,k,ans);
        return ans;
    }
    void helper(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, 
    unordered_map<TreeNode*, bool> &vis, int dist, int k, vector<int>& ans){
        if(dist==k) {
            ans.push_back(root->val);
            return;
        }
        vis[root]=1;
        if(root->left && !vis[root->left]){
            helper(root->left,parent,vis,dist+1,k,ans);
        }
        if(root->right && !vis[root->right]){
            helper(root->right,parent,vis,dist+1,k,ans);
        }
        if(parent.find(root)!=parent.end() && !vis[parent[root]]){
            helper(parent[root],parent,vis,dist+1,k,ans);
        }
    }
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mpp)
    {
        if(root==NULL) return;
        if(root->left){
            mpp[root->left]=root;
            markParents(root->left,mpp);
        }
        if(root->right){
            mpp[root->right]=root;
            markParents(root->right,mpp);
        }
    }
};