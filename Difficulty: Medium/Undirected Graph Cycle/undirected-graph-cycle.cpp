class Solution {
  public:
    bool detect(int src , vector<vector<int>>&adj , vector<bool>&vis){
        vis[src] = true;
        queue<pair<int,int>>que;
        que.push({src , -1});
        while(!que.empty()){
            int node = que.front().first;
            int parent = que.front().second;
            que.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    que.push({it , node});
                }
                else if(parent != it)
                    return true;
            }
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
        vector<bool>vis(V , false);
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                if(detect(i , adj , vis))
                    return true;
            }
        }
        return false;
    }
};