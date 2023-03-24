// DP with Binary Search Approach
class Solution {
    int solveDPBS(vector<int>& nums){
        int n = nums.size();
        
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{ // find the index of just larger element than nums[i] in ans
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();             
                ans[index] = nums[i];
            }
        }
        
        return ans.size();        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solveDPBS(nums);
    }
};