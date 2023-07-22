class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int left = 0 , right = 0;
        vector<int> freq(2); 
        
        int max_len = 0;
        
        while(right != nums.size())
        {
            // Adding new element to window
            freq[nums[right]]++;
            
            if(freq[0] <= k)
                max_len = max(max_len , right - left + 1);
            else if(freq[0] > k)
            {
                // shrinking window from front : removing first element
                freq[nums[left]]--;
                left++;
            }
            
            ++right;
        } 
        return max_len;
    }
};