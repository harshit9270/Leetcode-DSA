// Bottom Up DP
class Solution {
    int solveTab(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 and j == n-1)
                    dp[i][j]=grid[i][j];
                else{
                    int down = 1e9, right = 1e9;
                    if(i < m-1) // cannot go right if(i == m-1)
                        down = dp[i+1][j];
                    if(j < n-1) // cannot do down if(j == n-1)
                        right = dp[i][j+1];
                    
                    dp[i][j] = grid[i][j] + min(down, right);
                }
            }
        }
        
        return dp[0][0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return solveTab(grid);
    }
};