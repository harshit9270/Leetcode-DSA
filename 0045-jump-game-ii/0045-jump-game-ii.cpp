class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),10001);
        dp[nums.size()-1] = 0;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i] > 0 ){
            int mini = INT_MAX;
            for(int j=1;j<=nums[i] && j+i < n;j++){
                if(dp[i+j]!=10001){
                    mini = min(mini,dp[i+j]);
                }
            }
            if(mini != INT_MAX){
                dp[i]=min(mini+1,dp[i]);
            }
            else dp[i]=10001;
            }
        }
        return dp[0];
    }
};