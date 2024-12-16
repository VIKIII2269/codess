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
int ng(TreeNode* root)
{
    if (root==nullptr)
    return 0;
    if (ng(root->left)==-1)
    return -1;
    if (ng(root->right)==-1)
    return -1;
    if (abs(ng(root->right)-ng(root->left))>1)
    return -1;
    return 1+max(ng(root->right),ng(root->left));


}
    bool isBalanced(TreeNode* root) {
        int a=ng(root);
        if (a==-1)
        return false;
        return true;
    }
};