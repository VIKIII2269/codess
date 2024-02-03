class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p != NULL && q != NULL) {
            if (p->val != q->val)
                return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else if (p == NULL && q == NULL) {
            return true;
        } else {
            return false;
        }
    }
};
