class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] == -1) { 
                queue<int> q;
                q.push(start);
                color[start] = 0; // assign a starting color

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node]; // alternate color
                            q.push(it);
                        } 
                        else if (color[it] == color[node]) {
                            return false; // same color on adjacent nodes
                        }
                    }
                }
            }
        }
        return true;
    }
};
