class Solution {
  public:
    int solve(int i , int j ,vector<vector<int>>&dp){
        if(i == 1 || j == 1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i , j-1 , dp) + solve(i-1 , j , dp);
    }
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>>dp(m+1 , vector<int>(n+1,-1));
        return solve(m , n , dp);
    }
};
