class Solution 
{
public:
    bool isPal(string &s)
    {
        for(int i=0;i<s.length()/2;i++)
            if(s[i] != s[s.length()-i-1])
                return false;
        
        return true;
    }
    
    void helper(string &s,int index,vector<string>&curr,vector<vector<string>>&ans)
    {
        if(index==s.length())
        {
            ans.push_back(curr);
            return;
        }
        
        string tmp="";
        for(int i=index;i<s.length();i++)
        {
            tmp.push_back(s[i]);
            if(isPal(tmp))
            {
                curr.push_back(tmp);
                helper(s,i+1,curr,ans);
                // backtrack
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string>curr;
        vector<vector<string>>ans;
        
        helper(s,0,curr,ans);
        
        return ans;
    }
};