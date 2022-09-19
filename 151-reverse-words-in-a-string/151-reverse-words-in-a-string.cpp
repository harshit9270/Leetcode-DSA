class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s); // breaking input string into word using string stream 
                            
        string ans = "";
        string str;
        
        stack<string> st;
        while(ss >> str)     // read individual word in string str 
        {
           st.push(str);    
        }
        
        while(!st.empty())
        {
            if(ans.size())  
                ans+=' ';
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};