// Find maximum element in vector
// Find the length of longest subarray which contains only maximum element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int subarrayCnt = 0, ans = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxEle)
                subarrayCnt++;
            else{
                ans = max(ans, subarrayCnt);
                subarrayCnt = 0;
            }
        }

        return max(ans, subarrayCnt);
    }
};