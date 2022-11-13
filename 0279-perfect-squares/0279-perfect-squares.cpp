// Bottom-up DP Approach
class Solution {
    int solveTab(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        int ans = n;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= n; j++){
                int temp = j*j;
                if(i-temp >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }

        return dp[n];
    }
public:
    int numSquares(int n) {
        return solveTab(n);
    }
};