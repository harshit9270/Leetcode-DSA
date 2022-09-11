class Solution {
public:
    // Using binary search
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2)return nums[0] > nums[1] ? 0 : 1;
        
        int start = 1, end = n-2;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
                return mid;
            else if(nums[mid+1] > nums[mid]) 
                start = mid+1;
            else if(nums[mid-1] >= nums[mid]) 
                end = mid-1;
        }
        
        // Check for first and last elements seperately, if peak not found in between
        if(nums[0] > nums[1]) 
            return 0;
        else if(nums[n-1] > nums[n-2]) 
            return n-1;
        
        return -1;        
    }
};