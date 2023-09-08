// Simple Approach
// TC -> O(n^2)
// SC -> O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pTri;
        for(int i=0; i<numRows; i++){
            vector<int> row(i + 1, 1);
            
            for (int j = 1; j < i; j++)
                row[j] = pTri[i - 1][j] + pTri[i - 1][j - 1];
            
            pTri.push_back(row);     
        }
        
        return pTri;
    }
};