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

        
    int largestRectangleArea(vector<int>& h) {
        vector <int> n=nse(h);
        vector <int> p=pse(h);
        int area=0;
        for (int i=0;i<h.size();i++)
        {area=max(area,h[i]*(n[i]-p[i]-1));

        }
        return area;
    }
};