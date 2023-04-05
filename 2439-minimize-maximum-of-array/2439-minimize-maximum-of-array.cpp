// Binary Search
class Solution {
public:
    bool valid(int mid,vector<int> nums){
        long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > (long)mid*(i+1)) 
                return false;
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0;
        int right = *max_element(nums.begin(),nums.end());
        int ans = 0;
        
        while(left <= right){
            int mid = (left + right)/2;
            if(valid(mid,nums)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};