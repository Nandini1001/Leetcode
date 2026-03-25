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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int> inmap;
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
        }
        return helper(preorder, inorder, 0, n-1, 0, n-1, inmap);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int psi, int pei, int isi, int iei, unordered_map<int,int>& inmap){
        if(pei<psi || isi>iei) return NULL;
        TreeNode* root=new TreeNode(preorder[psi]);
        int inorder_ind=inmap[preorder[psi]];
        int noofelements=inorder_ind-isi;
        root->left=helper(preorder, inorder, psi+1 , psi+noofelements, isi, inorder_ind-1, inmap);
        root->right=helper(preorder, inorder, psi+1+noofelements , pei, inorder_ind+1, iei, inmap);
        return root;
    }
};