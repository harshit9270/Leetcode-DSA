// Here we are exploiting the property of bfs of stopping traversal once a component is completely traversed, 
// Once a component is traversed it will not traverse another component by itself
// Since, valid path does not exists for disconnected start and end

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // adj list
        unordered_map<int,vector<int>> adj; 
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if(curr == end)
                return 1; 
            for(auto & nbr : adj[curr]){
                if(!visited[nbr]){
                    visited[nbr] = 1; 
                    q.push(nbr);
                }
            }
        }
        
        return false;
    }
};