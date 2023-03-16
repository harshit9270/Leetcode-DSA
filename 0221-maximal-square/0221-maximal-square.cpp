// Top down DP
class Solution {
    int solveMem(vector<vector<char>>& matrix, int i, int j, int& maxi, vector<vector<int>>& dp){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solveMem(matrix, i, j+1, maxi, dp);
        int diagonal = solveMem(matrix, i+1, j+1, maxi, dp);
        int down = solveMem(matrix, i+1, j, maxi, dp);
        
        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;        
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = 0;
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        solveMem(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};