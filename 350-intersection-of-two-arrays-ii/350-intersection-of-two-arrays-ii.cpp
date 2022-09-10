class Solution {
public:
    // Using map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> output;
        
        // inserting all elements along with freq of nums1 into map
        for(auto i : nums1)
            mp[i] ++;
        
        for(int i=0; i<nums2.size(); i++){
            if(mp.find(nums2[i]) != mp.end() && mp[nums2[i]] > 0){
                output.push_back(nums2[i]);
                mp[nums2[i]] --;
            }                
        }
        
        return output;        
    }
};