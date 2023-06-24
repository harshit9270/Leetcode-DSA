class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> dist;
        
        for(char ch : s)
            dist.insert(ch);
        
        return dist.size();
    }
};