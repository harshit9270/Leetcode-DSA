class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        
        for(char ch : t)
            mp[ch] ++;
        
        int count = 0, minLen=INT_MAX, start = 0;
        
        while(right < s.size()){
            if (mp[s[right]] > 0)
                count++;
            
            mp[s[right]] --;
            right++;
            
            while (count == t.length()) {
                if(minLen > right-left){
                    minLen = right-left;
                    start = left;
                }
                
                mp[s[left]] ++;
                if (mp[s[left]] > 0)
                    count--;
                left++;
            }          
            
        }
        
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};