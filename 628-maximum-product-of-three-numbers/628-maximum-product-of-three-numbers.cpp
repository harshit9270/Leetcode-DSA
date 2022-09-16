// Single Scan Approach
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX,
        min2 = INT_MAX,
        max1 = INT_MIN,
        max2 = INT_MIN,
        max3 = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            } 
            else if (nums[i] <= min2)      // n lies between min1 and min2
                min2 = nums[i];
            
            if (nums[i] >= max1) {            // n is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } 
            else if (nums[i] >= max2) {     // n lies betweeen max1 and max2
                max3 = max2;
                max2 = nums[i];
            } 
            else if (nums[i] >= max3)      // n lies betwen max2 and max3
                max3 = nums[i];
            
        }
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};