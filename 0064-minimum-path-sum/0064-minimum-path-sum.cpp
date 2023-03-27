// Top Down DP
class Solution {
    int solveMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size(), n = grid[0].size();
        if(i == m-1 && j == n-1)
            return grid[i][j];
        
        if(i == m || j == n)
            return 1e9;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = grid[i][j] + solveMem(grid, i+1, j, dp);
        int right = grid[i][j] + solveMem(grid, i, j+1, dp);
        
        return dp[i][j] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solveMem(grid, 0, 0, dp);
    }
};