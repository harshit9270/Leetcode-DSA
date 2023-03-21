class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long curr_len = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                curr_len ++;
            else{
                count += (curr_len * (curr_len + 1))/2;
                curr_len = 0;
            }
        }
        
        if(curr_len != 0)
            count += (curr_len * (curr_len + 1))/2;
        
        return count;
    }
};