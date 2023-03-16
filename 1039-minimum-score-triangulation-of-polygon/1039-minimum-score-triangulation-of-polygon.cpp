// Top down DP
class Solution {
    int solveMem(vector<int>& v, int i, int j, vector<vector<int>>& dp){
        if(i+1 == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            // MCM pattern
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
        }
        
        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solveMem(values, 0, n-1, dp);
    }
};