// First find the maximum subarray sum using the standard Kadane's algorithm, and then check if there's a better solution by finding the minimum subarray sum and subtracting it from the total sum of the array.
// This approach considers the case where the maximum subarray sum is obtained from the subarray that "wraps around" the circular array.
    
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        
        for (int x : nums) {
            curMax = max(x, curMax + x);  //update the current max subarray sum
            maxSum = max(maxSum, curMax); //update the overall max subarray sum
            curMin = min(x, curMin + x);  //update the current min subarray sum
            minSum = min(minSum, curMin); //update the overall min subarray sum
            totalSum += x;
        }
        
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};