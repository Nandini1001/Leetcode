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
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        vector<int> binary;
        dfs(root, binary, sum);
        return sum;
    }
    int decimal(vector<int> &s){
        int no=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[n-i-1]) no+=pow(2,i);
        }
        return no;
    }
    void dfs(TreeNode* node, vector<int>& binary, int &sum){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL){
            binary.push_back(node->val);
            sum+=decimal(binary);
            binary.pop_back();
            return;
        }
        binary.push_back(node->val);
        dfs(node->left, binary, sum);
        dfs(node->right, binary, sum);
        binary.pop_back();
    }
};