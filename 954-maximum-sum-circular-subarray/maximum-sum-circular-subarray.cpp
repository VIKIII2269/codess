#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& arr) {
        int n = arr.size();

        
        int maxSubarraySum = arr[0];
        int currentMax = arr[0];
        for (int i = 1; i < n; i++) {
            currentMax = std::max(arr[i], currentMax + arr[i]);
            maxSubarraySum = std::max(maxSubarraySum, currentMax);
        }

        
        int totalSum = arr[0];
        int minSubarraySum = arr[0];
        int currentMin = arr[0];
        for (int i = 1; i < n; i++) {
            totalSum += arr[i];
            currentMin = std::min(arr[i], currentMin + arr[i]);
            minSubarraySum = std::min(minSubarraySum, currentMin);
        }

       
        if (totalSum == minSubarraySum) {
            return maxSubarraySum;
        }

        
        return std::max(maxSubarraySum, totalSum - minSubarraySum);
    }
};
