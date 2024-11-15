#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0) {
                
                ans.push_back(a[i]);
            } else {
               
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(a[i])) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() == abs(a[i])) {
                    ans.pop_back();  
                } else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(a[i]);  
                }
            }
        }
        return ans;
    }
};
