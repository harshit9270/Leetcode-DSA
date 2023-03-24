// Using Sorting + Longest Increasing Subsequence(DP with Binary Search Approach)

class Solution {
    int solveLIS(vector<int>& nums){
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
    
    static bool cmp(vector<int> & a, vector<int> & b){
        // increasing order of width
        // if width matches, decreasing order of height
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> heights;
        
        for(vector<int> & v : envelopes)
            heights.push_back(v[1]);
        
        return solveLIS(heights);
    }
};