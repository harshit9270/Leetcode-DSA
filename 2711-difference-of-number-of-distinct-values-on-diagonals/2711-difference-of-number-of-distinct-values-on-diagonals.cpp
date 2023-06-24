// Brute Force Approach
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int r=i, c=j;
                unordered_set<int> s_top_left;
                while(--r >= 0 && --c>=0)
                    s_top_left.insert(grid[r][c]);
                
                r=i, c=j;
                unordered_set<int> s_bottom_right;
                while(++r < m && ++c < n)
                    s_bottom_right.insert(grid[r][c]);

                answer[i][j] = s_top_left.size() - s_bottom_right.size();
                // Doing this coz abs is throwing error
                if(answer[i][j] < 0)
                    answer[i][j] *= -1;
            }
        }
        
        return answer;
    }
};