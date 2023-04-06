// DFS
class Solution { 
    bool isvalid(int x, int y, int m, int n, vector <vector <int>>&grid, vector <vector <int>>&visited){
        if(visited[x][y] or grid[x][y]) 
            return false;
        
        return true;
    }
    
    bool dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&visited){
        if(! isvalid(x, y, grid.size(), grid[0].size(), grid, visited)) 
            return true;
        
        if(x==grid.size()-1 or x==0 or y==grid[0].size()-1 or y==0) 
            return false;
        
        visited[x][y] = 1;
        
        bool left = dfs(x, y-1, grid, visited);
        bool right = dfs(x, y+1, grid, visited);
        bool up = dfs(x-1, y, grid, visited);
        bool down = dfs(x+1, y, grid, visited);
        
        return left and right and up and down;
    }
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector <int>(n,0));
        
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0 and visited[i][j]==0)
                    count += dfs(i,j,grid,visited);
            }
        }
        
        return count;
    }
};