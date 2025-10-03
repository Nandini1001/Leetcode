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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        // Get the in-order traversal of the BST
        inorderTraversal(root, inorder);

        // Apply two-pointer approach
        // on the in-order array
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            
            // Calculate sum of elements
            // at left and right pointers
            int sum = inorder[left] + inorder[right];
            if (sum == k) {
                // Pair found
                return true; 
                
            } else if (sum < k) {
                // Increment left pointer
                left++; 
                
            } else {
                // Decrement right pointer
                right--; 
            }
        }
        
        // No pair found
        return false; 
    }

private:
    // Helper function to perform in-order
    // traversal and populate the vector
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root) {
            return;
        }
        // Traverse left subtree
        inorderTraversal(root->left, inorder); 
        
        // Push current node's value to vector
        inorder.push_back(root->val); 
        
        // Traverse right subtree
        inorderTraversal(root->right, inorder); 
    }
};