class Solution {
    bool isVowel(char ch){
        if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'
            or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
            return true;
        return false;
    }
public:
    string sortVowels(string s) {
        multiset<char> st;
        vector<int> idx;
        for(int i=0; i<s.size(); i++)
            if (isVowel(s[i])){
                st.insert(s[i]);
                idx.push_back(i);
            }
        
        int i=0;
        for(auto it : st)
            s[idx[i++]] = it;
        
        return s;
    }
};