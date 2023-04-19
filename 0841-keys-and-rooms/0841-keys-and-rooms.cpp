class Solution {
public:
    void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        
        dfs(rooms, 0, vis);
        
        for(int i = 0; i < rooms.size(); i++){
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};