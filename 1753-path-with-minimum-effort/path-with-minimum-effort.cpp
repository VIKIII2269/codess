#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

       
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        pq.push({0, 0, 0}); 
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [currEffort, r, c] = pq.top();
            pq.pop();

            
            if (r == n-1 && c == m-1) return currEffort;

            
            if (currEffort > effort[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nextEffort = max(currEffort, abs(grid[r][c] - grid[nr][nc]));

                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }

        return 0; 
    }
};
