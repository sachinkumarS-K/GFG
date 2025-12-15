// User function Template for C++

class Solution {
  public:
    void dfs(int c , vector<int>adjList[] , vector<bool>&vis){

        vis[c] = true;
        for(auto i : adjList[c]){
            if(!vis[i]){
                dfs(i , adjList , vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        vector<int> adjList[v + 1];
        for(int i = 0 ; i<v ; i++){
            for(int j = 0 ; j<v ; j++)
                if(adj[i][j] == 1 && i != j){
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
        }
        vector<bool>vis(v+1 , false);
        int count = 0;
        
        for(int i = 1 ; i<=v ; i++){
            if(!vis[i]){
                count++;
                dfs(i , adjList,vis);
            }
        }
    
        
        return count;
    }
};