class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        
        for(vector<int> & v : nums)
            sort(v.begin(), v.end());
        
        int n = nums[0].size();
        
        while(n--){
            int maxi = INT_MIN;
            for(vector<int> & v : nums){
                int back = v.back();
                v.pop_back();

                maxi = max(back, maxi);
            }
            
            score += maxi;
        }
        
        return score;
    }
};