class Solution {
public:
    bool checkNextPermutation(vector<int>& nums) {
	    // Narayana Panditha's Algorithm
        int len=nums.size(), k=0, l=0;
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0){
            // No such integer exists
            return false;
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
        
        return true;
    }
    
    int nextGreaterElement(int n) {
        vector<int> nums;
        while(n){
            nums.insert(nums.begin(), n%10);
            n /= 10;
        }
        
        if(!checkNextPermutation(nums))
            return -1;
        
        int res = 0;
        
        for(int i=0; i<nums.size(); i++){
            // checking if 32-bit integer overflow can occur
            if(res > (INT_MAX-nums[i])/10)
                return -1;
            res = res*10 + nums[i];
        }
        
        return res;
    }
};