class Solution {
  public:
    bool dfs(int node , int parent , vector<vector<int>>&adj , vector<bool>&vis){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i , node , adj , vis))
                    return true;
            }
            else if(i != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i = 0 ; i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(V,false);
        for(int i = 0 ; i<V;i++){
            if(!vis[i]){
                if(dfs(i ,-1 ,adj , vis))
                    return true;
            }
        }
        return false;
    }
};