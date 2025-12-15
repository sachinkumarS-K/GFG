class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>ans;
        vector<bool>vis(n , false);
    
        queue<int>que;
        int src = 0 ;
        vis[src] = true;
        que.push(src);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            ans.push_back(curr);
            
            for(auto x : adj[curr]){
                if(!vis[x]){
                    vis[x] = true;
                    que.push(x);
                }
            }
        }
        
        return ans;
    }
};