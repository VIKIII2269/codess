class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0, i = 0;
        vector<int> p(256, -1);

        for (int j = 0; j < n; j++) {
            i = max(i, p[s[j]] + 1);
            res = max(res, j - i + 1);
            p[s[j]] = j;
        }

        return res;
    }
};
