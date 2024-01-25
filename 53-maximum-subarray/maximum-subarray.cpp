class Solution {
public:
    int maxSubArray(vector<int>& arr) {
       int res=arr[0];
       int maxe=arr[0];
       for( int i=1;i<arr.size();i++)
       {maxe=max(maxe+arr[i],arr[i]);
       res=max(res,maxe);

       }
       return res;

       
    }
};