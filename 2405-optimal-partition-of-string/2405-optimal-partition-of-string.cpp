class Solution {
public:
    int partitionString(string s) {
        map<char, int> mp;
        int ans = 1;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(mp.find(ch) != mp.end()) {
                ans++;
                mp.clear();
            }

            mp[ch]++;
        }
        
        return ans;
    }
};