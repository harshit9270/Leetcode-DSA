class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n, 0);
        
        int curr = 0;        
        int i = 0;
        while (true) {
            int nxt = (curr + i*k)%n;
            if (vis[nxt]) 
                break;
            
            vis[nxt] = 1;
            curr = nxt;
            ++ i;
        }
        
        vector<int> ans;        
        for (int i=0; i<n; ++i)
            if (!vis[i]) 
                ans.push_back(i + 1);
        
        return ans;
    }
};