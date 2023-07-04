// Using unordered_set & unordered_map (Extra space but linear time)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        
        for(int i : nums){
            freq[i] ++;
            if(freq[i] > 1)
                s.erase(i);
        }
        
        return *s.begin();
    }
};