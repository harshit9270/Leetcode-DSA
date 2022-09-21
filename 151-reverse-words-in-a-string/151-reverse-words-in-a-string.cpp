class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                if(temp == "")
                    continue;
                
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += " ";
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        while(ans[ans.size()-1] == ' ')
            ans.pop_back();
        
        return ans;
    }
};