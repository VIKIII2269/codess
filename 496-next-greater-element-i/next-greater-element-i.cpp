#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; 
        stack<int> s;                   
        
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop(); 
            }
            ngeMap[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(ngeMap[num]);
        }
        
        return ans;
    }
};
