class Solution {
public:
    // Using map
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for(auto i : nums){
            freq[i]++;
            if(freq[i] > nums.size()/3){
                if(find(ans.begin(), ans.end(), i) == ans.end())
                    ans.push_back(i);
            }
        }
        
        return ans;
    }
};