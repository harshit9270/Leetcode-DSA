// Top-down DP Approach
class Solution {
    int solveRec(vector<int> & coins, int amount, vector<int> &dp){
        if(amount == 0)
            return 0;
        if(amount < 0)
            return INT_MAX;
        
        if(dp[amount] != -1)
            return dp[amount];
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveRec(coins, amount-coins[i], dp);
            if(ans != INT_MAX)
                mini = min(mini, 1+ans);
        }
        
        dp[amount] = mini;
        
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        
        int ans = solveRec(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};