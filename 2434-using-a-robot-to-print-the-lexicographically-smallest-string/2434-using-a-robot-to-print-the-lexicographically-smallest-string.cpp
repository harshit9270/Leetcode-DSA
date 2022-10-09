class Solution {
public:
    // Intuition: we print a character at the end of t if it's smaller or equal any remaining characters in s.
    // We can use a counter to track remaining characters. We reduce the counter as we move a character from s to t.
    // Since we only care about the smallest among remaining characters, we track it using lo.
    // Please note that we may need to update lo when we move a character from s to t.
    
    string robotWithString(string s) {
        string p, t;
        int cnt[26] = {}, lo = 0;
        
        for(auto ch : s)
            ++cnt[ch - 'a'];
        
        for (auto ch : s) {
            t += ch;
            --cnt[ch - 'a'];
            
            // traverse to the smallest char present now in s
            while(lo < 26 && cnt[lo] == 0)
                ++lo;
            
            while(!t.empty() && t.back() - 'a' <= lo) {
                p += t.back();
                t.pop_back();
            }
        }
        
        return p;
    }
};