class Solution {
    private:
    bool dfs(int node , vector<vector<int>> &adj , vector<bool>&vis , vector<bool>&pathVis){
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto it : adj[node]){
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }
        
        pathVis[node] = false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>adj(V);
        for(int i = 0 ; i<edges.size() ; i++){
            for(int j = 0 ; j<2 ; j++){
                adj[edges[i][0]].push_back(edges[i][1]);
            }
        }
        vector<bool>vis(V,false);
        vector<bool>pathVis(V , false);
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                if(dfs(i , adj , vis , pathVis))
                    return true;
            }
        }
        return false;
    }
};