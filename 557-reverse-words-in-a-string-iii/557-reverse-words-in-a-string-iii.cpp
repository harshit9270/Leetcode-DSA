// Using Stack
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
                res += " ";
            }
            else{
                st.push(s[i]);
            }
        }
        
        // handling the last word
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};