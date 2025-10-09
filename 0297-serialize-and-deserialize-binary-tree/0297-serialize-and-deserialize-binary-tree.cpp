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
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        vector<string> vals;
        while(getline(ss, str, ',')){
            vals.push_back(str);
        }
        TreeNode* root=new TreeNode(stoi(vals[0]));
        //TreeNode *root=node;
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(vals[i]=="null") node->left=nullptr;
            else{
                TreeNode* left=new TreeNode(stoi(vals[i]));
                q.push(left);
                node->left=left;
            }
            i++;
            if(vals[i]=="null") node->right=nullptr;
            else{
                TreeNode* rt=new TreeNode(stoi(vals[i]));
                q.push(rt);
                node->right=rt;
            }
            i++;
        }
        return root;
        /*if (data.empty()) return nullptr;

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

        return root;*/
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));