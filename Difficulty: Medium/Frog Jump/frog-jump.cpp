class Solution {
  public:
    int solve(vector<int>&arr , int n , vector<int>&dp){
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
            
        int a = solve(arr , n-1 , dp) + abs(arr[n] - arr[n-1]);
        int b = INT_MAX;
        if(n > 1){
            b = solve(arr , n-2 , dp) + abs(arr[n] - arr[n-2]);
        }
        return dp[n] = min(a , b);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n+1 , -1);
        return solve(height , n-1 , dp);
    }
};