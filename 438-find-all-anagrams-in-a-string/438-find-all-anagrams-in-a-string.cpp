class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>idx;
        int i;
        int n=s.size();
        int m=p.size();
        if(m>n)
            return idx;
       
        vector<int>freq(26,0),freq1(26,0);
        for(auto i:p)
            freq[i-'a']++;
        
        for(i=0;i<m;i++)
            freq1[s[i]-'a']++;
        
        for(i=m;i<n;i++)
        {
            
            if(freq==freq1)
                idx.push_back(i-m);
            
            freq1[s[i]-'a']++;
            freq1[s[i-m]-'a']--;
        }
        
          if(freq==freq1)
                idx.push_back(i-m);
        
        return idx;
        
    }
};