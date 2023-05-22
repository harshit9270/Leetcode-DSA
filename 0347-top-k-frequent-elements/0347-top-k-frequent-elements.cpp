class Solution {
public:
    
    // Custom Compare to sort in descending order
    bool static compare(pair<int,int>&p1,pair<int,int>&p2) {
        return p1.second > p2.second;
    }
    
    //Solution Body
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<pair<int, int>> v;
        vector<int> ans;
        
        //Setup the hashtable/hashmap to freq of occurrence of values from nums
        for(auto n:nums) {
            hash[n]++;
        }
        
        // Corner case
        if(k>hash.size()) {
            return ans;
        }
        
        // Make pair of Value and its frequency
        for(auto i:hash) {
            v.push_back({i.first, i.second});
        }
        
        // Sort in desc order for frequencies
        sort(v.begin(), v.end(), compare);
        
        // Store top k repeating nums in ans
        for(int p=0; p<k; p++) {
            ans.push_back(v[p].first);
        }
        
        return ans;
        
    }
};