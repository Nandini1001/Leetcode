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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //using preorder
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>> mpp;
        inorder(root,mpp,0,0);
        for(auto p:mpp){
            vector<int> vertical;
            for(auto q:p.second){
                vertical.insert(vertical.end(),q.second.begin(),
                q.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
    void inorder(TreeNode* root, map<int,map<int,multiset<int>>> &mpp, int vertical, int level){
        if(root==NULL) return;
        inorder(root->left,mpp,vertical-1,level+1);
        mpp[vertical][level].insert(root->val);
        inorder(root->right,mpp,vertical+1,level+1);
    }
};