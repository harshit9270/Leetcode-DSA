// Top Down DP
class Solution {
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp){
        if(index == nums1.size())
            return 0;
        
        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        
        int ans = 1e9;
        int prev1 = nums1[index-1], prev2 = nums2[index-1];
        
        if(swapped)
            swap(prev1, prev2);
        
        // no swap
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        
        // swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solveMem(nums1, nums2, index+1, 1, dp));
        
        return dp[index][swapped] = ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        
        return solveMem(nums1, nums2, 1, 0, dp);
    }
};