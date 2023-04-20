// Not optimal
// O(n^2)
class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        if(start >= end)
            return true;
        
        if(s[start] != s[end])
            return false;
        
        return isPalindrome(s, start+1, end-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(isPalindrome(s, i, j)){
                    if(ans.size() < j-i+1)
                        ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};