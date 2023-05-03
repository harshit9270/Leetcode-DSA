// Using unordered map
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;
        vector<vector<int>> ans(2, vector<int>(0, 0));
        
        for(int i : nums1)
            freq1[i] ++;
        
        for(int i : nums2)
            freq2[i] ++;
        
        for(int i : nums2){
            if(freq1.find(i) == freq1.end()){
                if(freq2[i] == 1)
                    ans[1].push_back(i);
                else
                    freq2[i] --;
            }
        }        
        
        for(int i : nums1){
            if(freq2.find(i) == freq2.end())
                if(freq1[i] == 1)
                    ans[0].push_back(i);
                else
                    freq1[i] --;
        }
        
        return ans;
    }
};