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
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* prev;
        TreeNode* last;
        TreeNode* mid;
        TreeNode* first;
        first=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root,prev,first,last, mid);
        swap(first->val, last->val);
    }
    void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, 
    TreeNode*& last, TreeNode*& mid){
        if(root==NULL) return;
        inorder(root->left,prev,first,last, mid);
        if( root->val<prev->val){
            if(!first){
                first=prev;
                last=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right,prev,first,last,mid);
    }
};

//previous using global this pass by reference
//try not to store prev as node rather store only prev as int value but not possible as we have to make prev as first node also.
