// Using hashmap
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        map<string, vector<string>> mp;
        
        for(string s : strs){
            string temp = s;
            
            sort(temp.begin(), temp.end());
            mp[temp] .push_back(s);
        }
        
        auto it = mp.begin();
        while(it != mp.end()){
            res.push_back(it->second);
            
            it++;
        }
        
        return res;
    }
};