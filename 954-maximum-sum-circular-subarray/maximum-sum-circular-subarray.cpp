

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();

        
        int maxSubarraySum = arr[0];
        int currentMax = arr[0];
        for (int i = 1; i < n; i++) {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSubarraySum = max(maxSubarraySum, currentMax);
        }

        
        int totalSum = arr[0];
        int minSubarraySum = arr[0];
        int currentMin = arr[0];
        for (int i = 1; i < n; i++) {
            totalSum += arr[i];
            currentMin = min(arr[i], currentMin + arr[i]);
            minSubarraySum = min(minSubarraySum, currentMin);
        }

       
        if (totalSum == minSubarraySum) {
            return maxSubarraySum;
        }

        
        return max(maxSubarraySum, totalSum - minSubarraySum);
    }
};
