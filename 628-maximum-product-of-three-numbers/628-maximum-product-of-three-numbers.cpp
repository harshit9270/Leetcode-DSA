// Sorting Approach
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        
        sort(nums.begin(), nums.end());
        
        maxProduct = max(maxProduct, nums[0]*nums[1]*nums[n-1]);
        maxProduct = max(maxProduct, nums[n-3]*nums[n-2]*nums[n-1]);
                                                              
        return maxProduct;
    }
};