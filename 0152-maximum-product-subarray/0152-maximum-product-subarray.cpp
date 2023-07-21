// Optimal O(n), O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];
        
        int max_so_far = nums[0];
        
        for(int i=1 ; i <nums.size(); i++){
            int temp = max(max(nums[i], nums[i]*max_ending_here), nums[i]*min_ending_here);
            
            min_ending_here = min(min(nums[i], nums[i]*max_ending_here), nums[i]*min_ending_here);
            max_ending_here = temp;
            
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        return max_so_far;
    }
};