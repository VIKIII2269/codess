class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int x, y, d;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            x = points[i][0];
            y = points[i][1];
            d = x * x + y * y;
            pq.push({d, {x, y}});
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
