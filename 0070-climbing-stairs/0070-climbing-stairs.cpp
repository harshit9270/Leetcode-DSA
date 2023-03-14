// Bottom up DP
class Solution {
    int solve(int n){
        vector<int> dp(n+2);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
public:
    int climbStairs(int n) {        
        return solve(n);
    }
};