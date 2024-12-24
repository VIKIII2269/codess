class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {}; // Handle edge case where root is nullptr
        
        // Map to store the vertical order traversal
        map<int, map<int, multiset<int>>> m;
        
        // Queue for level-order traversal with (node, (vertical, level))
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            
            // Insert the node value into the map
            m[x][y].insert(node->val);
            
            // Push left and right children to the queue
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        // Prepare the result
        vector<vector<int>> ans;
        for (auto& [x, levelMap] : m) {
            vector<int> col;
            for (auto& [y, nodes] : levelMap) {
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
