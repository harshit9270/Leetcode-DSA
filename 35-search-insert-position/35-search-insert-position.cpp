class Solution {
public:
    // Using Binary search
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target){
                ans = mid+1;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        
        return ans;
    }
};