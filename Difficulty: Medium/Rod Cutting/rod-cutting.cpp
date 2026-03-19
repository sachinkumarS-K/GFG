// User function Template for C++

class Solution {
  public:
    int solve(int i , int n , vector<int>&arr , vector<vector<int>>&dp){
        if(n == 0 || i >= arr.size()) return 0;
        if(dp[i][n] != -1)  return dp[i][n];
        int inc = 0;
        if(n-(i+1) >= 0)
            inc = arr[i] + solve(i , n-(i+1) , arr , dp);
        int exc = solve(i+1 , n , arr , dp);
        
        return dp[i][n] = max(inc , exc);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        return solve(0 ,n , price , dp);
    }
};