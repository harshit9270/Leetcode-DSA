// Using stack
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(char ch : s){
            if(ch == 'B' && !st.empty() && st.top() == 'A')
                st.pop();
            else if(ch == 'D' && !st.empty() && st.top() == 'C')
                st.pop();
            else
                st.push(ch);
        }
        
        return st.size();
    }
};