class Solution {
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans, prefixSum;
        
        prefixSum.push_back(0);
        
        for(string & s : words){
            if(isVowel(s[0]) && isVowel(s[s.size()-1]))
                prefixSum.push_back(prefixSum.back() + 1);
            else
                prefixSum.push_back(prefixSum.back());
        }
        
        for(vector<int> & q : queries){
            ans.push_back(prefixSum[q[1]+1] - prefixSum[q[0]]);
        }
        
        return ans;
    }
};