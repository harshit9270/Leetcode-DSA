// Using Binary Search
class Solution {
public:
    int divisionRes(vector<int> &nums, int divisor){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]/divisor;
            // add 1 to sum inorder to get round-off value of division
            if(nums[i]%divisor)
                sum++;
        }    
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1000001, ans;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(divisionRes(nums, mid) > threshold)
                low = mid+1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        
        return ans;
    }
};