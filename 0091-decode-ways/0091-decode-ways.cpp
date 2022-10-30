// DP
class Solution {
public:
    int numDecodings(string s) {
        int prev_i_ways = 1, i_ways = 1, prev;
        if (!s.size()) return 0;
        if (s[0] == '0') return 0;
        
        for (int i = 1; i < s.size(); i++) {
            prev = i_ways;
            if (s[i] == '0') i_ways = 0;
            if ((s[i-1] == '1') || (s[i-1] == '2' && s[i] < '7')) i_ways += prev_i_ways;
            prev_i_ways = prev;
        }
        return i_ways;
    }
};