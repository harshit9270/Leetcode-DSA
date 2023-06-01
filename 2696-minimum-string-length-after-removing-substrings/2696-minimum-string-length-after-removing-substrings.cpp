// Using stack
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int minLen = s.size();
        
        for(char ch : s){
            if(ch == 'B' && !st.empty() && st.top() == 'A'){
                st.pop();
                minLen -= 2;
            }
            else if(ch == 'D' && !st.empty() && st.top() == 'C'){
                st.pop();
                minLen -= 2;
            }
            else
                st.push(ch);
        }
        
        return minLen;
    }
};