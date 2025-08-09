class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));
        int islandCount = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && v[i][j] == 0) {
                    q.push({i, j});
                    v[i][j] = 1; // mark visited
                    islandCount++;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                v[nr][nc] == 0 && grid[nr][nc] == '1') {
                                v[nr][nc] = 1; // mark visited immediately
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return islandCount;
    }
};
