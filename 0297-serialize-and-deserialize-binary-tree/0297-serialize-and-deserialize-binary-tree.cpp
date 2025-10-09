/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            s+=",";
            if(node->left){
                q.push(node->left);
                s+=to_string(node->left->val);
            }
            else s+="null";
            s+=",";
            if(node->right){
                q.push(node->right);
                s+=to_string(node->right->val);
            }
            else s+="null";
        }
        return s;
    }

    TreeNode* deserialize(string data) {
       /*if(data.size()==0) return NULL;
       TreeNode* node=new TreeNode(data[0]);
        TreeNode *root=node;
        queue<pair<TreeNode*, int>> q;
        q.push({node,0});
        while(!q.empty()){
            TreeNode *node=q.front().first;
            int ind=q.front().second;
            q.pop();
            if(data[2*ind+1]==null) node->left=NULL;
            else{
                TreeNode* left=new TreeNode(data[2*ind+1]);
                node->left=left;
                q.push({left,2*ind+1});
            }
            if(data[2*ind+2]==null) node->right=NULL;
            else{
                TreeNode* rt=new TreeNode(data[2*ind+2]);
                node->right=rt;
                q.push({rt,2*ind+2});
            }
        }
        return root;*/
         if (data.empty()) return nullptr;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if (!getline(ss, str, ',')) break;
            if (str != "null") {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }

            // right child
            if (!getline(ss, str, ',')) break;
            if (str != "null") {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));