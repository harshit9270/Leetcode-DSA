// Using hashmap
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(int i : nums){
            freq[i] ++;
            
            if(freq[i] > 1)
                return true;
        }
        
        return false;
    }
};