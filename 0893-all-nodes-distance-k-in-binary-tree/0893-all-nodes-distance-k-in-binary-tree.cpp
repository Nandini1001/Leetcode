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
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!queue.empty()){
            int n=queue.size();
            if(curr_level++==k) break;
            for(int i=0;i<n;i++){
                TreeNode* current=queue.front();
                queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int> res;
        while(!queue.empty()){
            TreeNode* current=queue.front();
            queue.pop();
            res.push_back(current->val);
        }
        return res;
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