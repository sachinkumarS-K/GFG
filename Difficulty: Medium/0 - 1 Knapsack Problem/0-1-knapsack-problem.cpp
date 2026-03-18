class Solution {
  public:
    int solve(int w , int i, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(i >= wt.size())  return 0;
        if(dp[i][w] != -1) return dp[i][w];
        int inc = 0;
        if(w-wt[i] >= 0)
            inc = val[i] + solve(w-wt[i] , i+1 , val , wt , dp);
        int exc = solve(w , i+1 , val ,wt , dp);
        return dp[i][w] = max(inc , exc);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(wt.size()+1, vector<int>(W+1 , -1));
        
        return solve(W, 0, val,wt,dp);
    }
};