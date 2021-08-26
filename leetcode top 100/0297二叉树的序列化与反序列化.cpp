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
        if(root==nullptr)return "#_";
        string res = to_string(root->val)+"_";
        res+=serialize(root->left);
        res+=serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;
        while(getline(ss,item,'_')){
            q.push(item);
        }
        return helper(q);
    }
    TreeNode* helper(queue<string>&q){
        string val = q.front();
        q.pop();
        if(val=="#")return nullptr;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
