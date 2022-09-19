// Using set

// Similar to the approach used in subsets-I
// Just one change, Using set as an extra to identify if this subset already exists or not
// If exists, then neglect it

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            if(s.find(temp) == s.end()){
                s.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        
        sub(nums, i+1, temp);
        temp.push_back(nums[i]);
        sub(nums, i+1, temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {  
        // We require sorting coz the problem considers both [4,4,4,1,4] & [1,4,4,4,4] same
        sort(nums.begin(), nums.end());
        sub(nums, 0, {});
        
        return ans;
    }
};