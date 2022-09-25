// Using monotonic stack approach
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> dec(nums.size(),1);
        vector<int> inc(nums.size(),1);
        
        vector<int> res;
        
        for(int i = 1;i<nums.size();i++){
            // if non-increasing condition occurs, then dec[i-1] is already 1,
            // no need for reset
            if(nums[i] <= nums[i-1])
                dec[i] = dec[i-1]+1;
        }
        
        for(int i = nums.size()-2;i>=0;i--){
            // same here, if non-decreasing condition occurs, then inc[i+1] is already 1, 
            // no need for reset
            if(nums[i] <= nums[i+1])
                inc[i] =inc[i+1]+1; 
        }
        
        for(int i = k;i<nums.size()-k;i++){
            if(dec[i-1] >=k && inc[i+1] >= k)
                res.push_back(i);
        }
        
        return res;
    }
};