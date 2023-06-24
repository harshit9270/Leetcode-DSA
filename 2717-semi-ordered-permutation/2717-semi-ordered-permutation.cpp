class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int s, e;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)
                s = i;
            else if(nums[i] == nums.size())
                e = i;
        }
        
        int ans = 0;
        if(s > e)
            ans -= 1;
        
        ans += s;
        ans += nums.size()-1-e;
        
        return ans;
    }
};