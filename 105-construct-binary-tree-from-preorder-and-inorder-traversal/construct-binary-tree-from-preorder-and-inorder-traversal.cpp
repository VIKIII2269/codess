#include <vector>
#include <map>
using namespace std;



class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }

private:
    TreeNode* build(const vector<int>& p, int ps, int pe, const vector<int>& i, int is, int ie, const map<int, int>& m) {
        if (ps > pe || is > ie)
            return nullptr;

        TreeNode* root = new TreeNode(p[ps]);
        int ir = m.at(root->val);
        int nl = ir - is;

        root->left = build(p, ps + 1, ps + nl, i, is, ir - 1, m);
        root->right = build(p, ps + nl + 1, pe, i, ir + 1, ie, m);

        return root;
    }
};
