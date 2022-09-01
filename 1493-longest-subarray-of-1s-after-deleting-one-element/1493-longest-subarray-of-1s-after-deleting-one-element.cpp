class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        int longestLength = 0;
        unordered_map<int, int> freq;
        
        while(end < nums.size()){
            freq[nums[end]] ++;
            
            while(freq[0] > 1 && start < end){
                freq[nums[start]] --;
                start++;
            }
            
            if(freq[0] >= 1)
                longestLength = max(longestLength, freq[1]);
            else
                longestLength = max(longestLength, freq[1]-1);
            
            end++;
        }
        
        return longestLength;
    }
};