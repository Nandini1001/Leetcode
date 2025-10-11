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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
    //reverse=true before
public:
    BSTIterator(TreeNode* root, int isreverse) {
        reverse=isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(!reverse && node->right) pushall(node->right);
        if(reverse && node->left) pushall(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse==true) root=root->right;
            else root=root->left;
        }
        /*st.push(root);
        if(!reverse){
            while(root->left){
                st.push(root->left);
                root=root->left;
            }
        }
        else{
            while(root->right){
                st.push(root->right);
                root=root->right;
            }
        }*/
    }
}; 

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true); //r.before()
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
    }
};