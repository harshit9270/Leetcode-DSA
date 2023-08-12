// Using hashmap
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numerals;
        numerals['I'] = 1;
        numerals['V'] = 5;
        numerals['X'] = 10;
        numerals['L'] = 50;
        numerals['C'] = 100;
        numerals['D'] = 500;
        numerals['M'] = 1000;
        
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (numerals[s[i]] < numerals[s[i+1]])
                res -= numerals[s[i]];
            else
                res += numerals[s[i]];
        }
        
        return res;
    }
};