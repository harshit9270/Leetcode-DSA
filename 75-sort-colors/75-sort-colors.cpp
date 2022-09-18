// DNF sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = nums.size()-1, k = 0;
        int i = 0;
        while(i <= j){
            if(nums[i] == 2)
                swap(nums[i],nums[j--]);
        
            else if(nums[i] == 0)
                swap(nums[i++],nums[k++]);
            
            else
                i++;
        }
    }   
};