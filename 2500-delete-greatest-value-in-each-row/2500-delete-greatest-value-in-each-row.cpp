class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        
        // sorting the vector
        for(vector<int> & v : grid)
            sort(v.rbegin(), v.rend());
        
        for(int i=0; i<grid[0].size(); i++){
            int max_in_col = INT_MIN;
            for(int j=0; j<grid.size(); j++){
                max_in_col = max(max_in_col, grid[j][i]);
            }
            ans += max_in_col;
        }        
        
        return ans;
    }
};