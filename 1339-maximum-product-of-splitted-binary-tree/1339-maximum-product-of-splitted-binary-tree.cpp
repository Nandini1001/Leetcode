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
    static const int mod=1e9+7;
    int maxProduct(TreeNode* root) {
        long long total=totalsum(root);
        long long prod=INT_MIN;
        helper(root, prod, total);
        //return (int)prod%mod;
        return (int)(prod%mod);
    }
    long long totalsum(TreeNode* root){
        long long sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
    long long helper(TreeNode* root, long long& prod, long long total){
        if(root==NULL) return 0;
        long long leftsum=helper(root->left, prod, total);
        prod=max(prod,leftsum*(total-leftsum));
        long long rightsum=helper(root->right, prod, total);
        prod=max(prod,rightsum*(total-rightsum));
        return root->val+leftsum+rightsum;
    }
};


//Casting has higher precedence than %, so this is evaluated as: return ((int)prod) % mod;
//❗ If prod is larger than INT_MAX, it gets truncated first, then modulo is applied → wrong answer.