class Solution {
  public:
    void dfs(vector<vector<int>>& adj , vector<bool>&vis , vector<int>&ans , int curr){
        if(vis[curr])
            return ;
        vis[curr] = true;
        ans.push_back(curr);
        for(auto it : adj[curr]){
            dfs(adj , vis , ans , it);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>vis(n , false);
        vector<int>ans;
        dfs(adj , vis , ans , 0);
        return ans;
    }
};