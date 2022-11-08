// Using Stack
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(ch >= 'a' && ch <= 'z'){
                // ch is an lowercase character
                if(!st.empty() && st.top() == ch - 32)
                    st.pop();
                else
                    st.push(ch);
            }
            else{
                // ch is an uppercase character
                
                if(!st.empty() && st.top() == ch + 32)
                    st.pop();
                else
                    st.push(ch);
            }            
        }
        
        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};