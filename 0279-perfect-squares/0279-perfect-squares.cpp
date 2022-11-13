// Top-down DP Approach
class Solution {
    int solveMem(int n, vector<int> & dp){
        if(n == 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int ans = n;
        for(int i=1; i*i <= n; i++){
            int temp = i*i;
            ans = min(ans, 1 + solveMem(n-temp, dp));
        }

        dp[n] = ans;
        
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};