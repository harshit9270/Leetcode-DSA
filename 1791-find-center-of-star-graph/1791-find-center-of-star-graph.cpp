// Using Adjacency List
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            if(adj[u].size() == edges.size())
                return u;
            if(adj[v].size() == edges.size())
                return v;
        }
        
        // never reached
        return 0;
    }
};