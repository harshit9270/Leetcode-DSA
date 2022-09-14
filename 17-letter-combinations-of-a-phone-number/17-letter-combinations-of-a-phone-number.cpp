class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.size()==0)
            return {};

        vector<string> res;
        res.push_back("");

        for(int k=0;k<digits.length();k++){
            vector<string> temp;
            string s = v[digits[k] - '0'];   


            for(int i=0;i<s.length();i++)
                for(int j=0;j<res.size();j++)
                     temp.push_back(res[j]+s[i]);
            
            // Here instead of pushing new combinations along with old ones to res,
            // we remove old ones and push new ones
            // So that at the end of the loop, we have only combinations of 
            // size == digits.size 
            
            swap(temp,res);
        }

        return res;
    }
};