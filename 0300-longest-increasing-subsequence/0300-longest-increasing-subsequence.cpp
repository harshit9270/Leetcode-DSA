// Bottom Up DP
class Solution {
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // include
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    take = 1 + dp[curr+1][curr+1];

                // exclude
                int notTake = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev + 1] = max(take, notTake);
            }
        }
        
        
        return dp[0][-1+1];        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solveTab(nums);
    }
};