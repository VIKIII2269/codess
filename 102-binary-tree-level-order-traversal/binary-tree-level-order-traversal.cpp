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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        if (root==NULL)
        return ans;
        while (!q.empty())
        {vector <int> lvl;
            int size=q.size();
            for (int i=0;i<size;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                lvl.push_back(n->val);


            }ans.push_back(lvl);
        }return ans;
        
    }
};