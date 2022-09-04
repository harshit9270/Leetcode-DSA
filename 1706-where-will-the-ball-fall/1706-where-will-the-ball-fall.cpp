class Solution {
public:
    int m, n;
    vector<int> ans;
    void dfs(vector<vector<int>>& grid, int curcol, int currow) {
        if(currow == m) {
            ans.push_back(curcol);
            return;
        }
        
        if(grid[currow][curcol] == 1) {
			// Check right-side cell
            if(curcol + 1 < n && grid[currow][curcol + 1] == 1) {
                dfs(grid, curcol + 1, currow + 1);
            }
            else {
                ans.push_back(-1);
                return;
            }
        }
        else if(grid[currow][curcol] == -1) {
			// Check left-side cell
            if(curcol - 1 >= 0 && grid[currow][curcol - 1] == -1) {
                dfs(grid, curcol - 1, currow + 1);
            }
            else {
                ans.push_back(-1);
                return;
            }
        }
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            dfs(grid, i, 0);
        }
        
        return ans;
    }
};