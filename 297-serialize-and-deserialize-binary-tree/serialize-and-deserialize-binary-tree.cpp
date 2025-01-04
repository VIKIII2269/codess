class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";  // Use "#" to represent an empty tree

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode) {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            } else {
                s += "#,";
            }
        }

        // Remove trailing comma
        if (!s.empty()) s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr; // Check if tree is empty

        stringstream s(data);
        string str;
        getline(s, str, ',');  // Extract root node value
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read left child value
            if (getline(s, str, ',')) {
                if (str != "#") {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }

            // Read right child value
            if (getline(s, str, ',')) {
                if (str != "#") {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
