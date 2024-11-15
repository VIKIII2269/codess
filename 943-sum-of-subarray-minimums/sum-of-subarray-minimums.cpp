class Solution {
public:
 vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); 
        stack<int> s; 
       
        for (int i =  n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop(); 
            }
            
               
                ans[i] = s.empty() ? n : s.top();
            
            s.push(i); 
        }
        return ans;
    }
    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); 
        stack<int> s; 
       
        for (int i =  0; i <n; i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop(); 
            }
            
               
                ans[i] = s.empty() ? -1 : s.top();
            
            s.push(i); 
        }
        return ans;
    }
     int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ns = nse(arr);
        vector<int> ps = pse(arr);
        long long total = 0, mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long l = i - ps[i];
            long long r = ns[i] - i;
            total = (total + (r * l % mod) * arr[i] % mod) % mod;
        }
        return static_cast<int>(total);
    }
};