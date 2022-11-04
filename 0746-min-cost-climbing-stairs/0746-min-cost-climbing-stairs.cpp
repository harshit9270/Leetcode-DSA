// Using Top-down DP
class Solution {
    int solve(vector<int> & cost, int n, vector<int> & dp){
        if(n <= 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        // cost for every climbed stair is added here (from 0 to n-1)
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n+1, -1);
        // Since there is no cost for climbing nth stair cost is not added here
        return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
};