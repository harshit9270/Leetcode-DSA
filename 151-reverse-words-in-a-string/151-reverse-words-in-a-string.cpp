// Using Stack
class Solution {
public:
    string reverseWords(string s) {        
        stack<string> st;
        
        for(int i =0;i<s.length();i++){
            string word=""; 
            
            if(s[i]==' ')
                continue;
            
            while(s[i]!=' ' and i<s.length()){
                word+=s[i];
                i++;
            }
            
            st.push(word);
        }
        
        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
            
            res += (st.empty()) ? "" : " ";
        }
        
        return res;
    }
};