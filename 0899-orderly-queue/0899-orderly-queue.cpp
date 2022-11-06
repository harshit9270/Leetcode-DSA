class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string ans = s;
            for(int i=1; i<ans.size(); i++)
                ans = min(ans, s.substr(i,s.size()-1) + s.substr(0,i));
            
            return ans;
        }
        else{
            sort(s.begin(),s.end());
            return s;
        }
    }
};