class Solution {
public:
    // MOORE'S VOTING ALGORITHM
    int majorityElement(vector<int>& nums) {
        int majority,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if (count == 0)
                majority = nums[i];
            count += nums[i] == majority ? 1 : -1;
        }
        return majority;
    }
};