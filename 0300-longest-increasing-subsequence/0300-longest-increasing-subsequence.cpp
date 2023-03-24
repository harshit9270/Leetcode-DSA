// Top Down DP
class Solution {
    int solveMem(vector<int>& nums, int curr, int prev, vector<vector<int>> & dp){
        if(curr == nums.size())
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // include
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            take = 1 + solveMem(nums, curr+1, curr, dp);
        
        // exclude
        int notTake = 0 + solveMem(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solveMem(nums, 0, -1, dp);
    }
};