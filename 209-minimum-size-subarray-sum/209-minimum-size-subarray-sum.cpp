// o(nlogn) solution -> Binary search + sliding window
class Solution {
public:
    bool checkPossible(int len, int target, vector<int> pre) {
        bool found = false;
        for(int i = len; i < pre.size(); i++) {
            int sum = pre[i] - pre[i-len];
            if(sum >= target)   
                return true;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {       
        // o(n log n) solution -> binary search
        int low = 1, high = nums.size()-1, res;
        
        vector<int> pre(nums.size()+1); 
        for(int i = 0; i < nums.size(); i++) 
            pre[i+1] = pre[i] + nums[i];
        
        int total = pre.back();
        if(total < target)    
            return 0;
        
        bool found = false;
        while(low <= high) {
            int mid = (low + high) / 2;
            
            found = checkPossible(mid, target, pre);
            
            if(found)   
                res = mid, high = mid-1;
            else    
                low = mid+1;            
        }
        
        return res;
    }
};