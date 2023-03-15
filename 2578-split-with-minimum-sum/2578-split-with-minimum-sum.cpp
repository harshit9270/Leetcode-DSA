class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        int n1 = 0, n2 = 0;
        
        for(int i=0; i<s.size(); i+=2)
            n1 = n1*10 + (s[i] - '0');
        
        for(int i=1; i<s.size(); i+=2)
            n2 = n2*10 + (s[i] - '0');
        
        return n1+n2;
    }
};