class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int m, p;
        
        for (int i = 0; i < arr.size(); i++) {
            m = abs(arr[i] - x);
            pq.push({m, arr[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
