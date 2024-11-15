class Solution {
public:
    vector<int> nse(vector<int>& a) {
        vector<int> nse(a.size());
        stack<int> s;

        for (int i = a.size() - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            nse[i] = s.empty() ? a.size() : s.top();
            s.push(i);
        }
        return nse;
    }

    vector<int> pse(vector<int>& a) {
        vector<int> pse(a.size());
        stack<int> s;

        for (int i = 0; i < a.size(); i++) {
            while (!s.empty() && a[s.top()] >= a[i]) {
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }

    int l(vector<int>& h) {
        vector<int> n = nse(h);
        vector<int> p = pse(h);
        int area = 0;
        for (int i = 0; i < h.size(); i++) {
            area = max(area, h[i] * (n[i] - p[i] - 1));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int ms = 0;
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (a[i][j] == '1') sum++;
                else sum = 0;
                psum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            ms = max(ms, l(psum[i]));
        }
        return ms;
    }
};
