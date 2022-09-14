// Using STL function next_permutation

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ourResult;
        vector<int> singleIter = nums;
		ourResult.push_back(singleIter);
        next_permutation(singleIter.begin(), singleIter.end());
        while (singleIter != nums)
        {
            ourResult.push_back(singleIter);
            next_permutation(singleIter.begin(), singleIter.end());
        }
        return ourResult;
    }
};