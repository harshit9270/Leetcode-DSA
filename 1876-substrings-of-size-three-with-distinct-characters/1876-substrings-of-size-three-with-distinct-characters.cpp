class Solution {
public:
    // Sliding window
    int countGoodSubstrings(string s) {
        string window = s.substr(0, 3);
        int count = 0;
        
        for(int i=3; i<=s.length(); i++){
            if(window[0] != window[1] && window[1] != window[2] && window[0] != window[2])
                count++;
            
            window.erase(0, 1);
            window += s[i];
        }
        
        return count;
    }
};