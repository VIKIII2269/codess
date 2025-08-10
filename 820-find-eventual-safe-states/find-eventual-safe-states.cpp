class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> safe;
        vector<vector<int>> r(n);
        vector<int> d(n, 0);
        for (int i = 0; i < g.size(); i++) {
            for (auto it : g[i]) {
                r[it].push_back(i);
                d[i]++;
            }}
            queue<int> q;
            for (int i = 0; i < g.size(); i++) {
                if (d[i] == 0)
                    q.push(i);
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                safe.push_back(node);
                for (auto it : r[node]) {
                    d[it]--;
                    if (d[it] == 0)
                        q.push(it);
                }
            }
            sort(safe.begin(), safe.end());
            return safe;
        }
    };