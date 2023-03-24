// Top Down DP
class Solution {
   int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp){
        // Base Case
        if(index == satisfaction.size())
            return 0;

        if(dp[index][time] != -1)
            return dp[index][time];

        int include = satisfaction[index] * (time+1) + solveMem(satisfaction, index+1, time+1, dp);

        int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

        dp[index][time] = max(include, exclude);

        return dp[index][time];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solveMem(satisfaction, 0, 0, dp);
    }
};