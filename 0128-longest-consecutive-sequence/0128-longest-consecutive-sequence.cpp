// Using hashsets
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        
        for(auto& num : s) {
            if(s.count(num - 1)) 
                continue;
            
            int j = 1;
            while(s.count(num + j)) j++;
            
            longest = max(longest, j);
        }
        
        return longest;
    }
};