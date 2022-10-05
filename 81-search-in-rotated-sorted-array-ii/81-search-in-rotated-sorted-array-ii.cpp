class Solution {
public:
    // Finding pivot element and then searching in both sides of pivot
    bool binarySearch(vector<int>& nums, int s, int e, int target) {
        int start=s, end=e;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int pivot;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                pivot = i;
                break;
            }
        }    
        
        bool searchFirst = binarySearch(nums, 0, pivot, target);
        
        return (!searchFirst) ? binarySearch(nums, pivot+1, nums.size()-1, target) : searchFirst;
    }
};