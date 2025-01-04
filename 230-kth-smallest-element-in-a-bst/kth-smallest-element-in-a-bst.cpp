class Solution {
public:
    int c = 0, result = -1;  // Counter and result storage
    
    void inorder(TreeNode* root, int k) {
        if (!root || c >= k) return;  // Stop if k-th element is found

        inorder(root->left, k);  // Traverse left subtree
        
        c++;  // Increment counter
        if (c == k) {
            result = root->val;  // Store result
            return;
        }
        
        inorder(root->right, k);  // Traverse right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
