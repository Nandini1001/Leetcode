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
    TreeNode* prev;
    TreeNode* last;
    TreeNode* mid;
    TreeNode* first;
public:
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        first=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(last) swap(first->val, last->val);
        else swap(first->val, mid->val);
    }
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if( root->val<prev->val){
            if(!first){
                first=prev;
                mid=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
};