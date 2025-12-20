class Solution {
  public:
    void dfs(int i , vector<vector<int>>&adj , vector<bool>&vis , stack<int>&stk){
        vis[i] = true;
        
        for(auto it : adj[i]){
            if(!vis[it])
                dfs(it , adj , vis, stk);
        }
        stk.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        int m = edges.size() ;
        for(int i = 0 ; i < m ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        stack<int>stk;
        vector<bool>vis(V , false);
        for(int i = 0 ; i<V ; i++){
            if(!vis[i])
                dfs(i , adj , vis , stk);
        }
        vector<int>ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};