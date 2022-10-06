// Using hashmap
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> mp;
        
        for(char ch : s)
            mp[ch] ++;
        
        for(char ch : t){
            if(mp.find(ch) != mp.end() && mp[ch] > 0){
                mp[ch] --;
            }
            else
                return false;
        }
        
        return true;
    }
};