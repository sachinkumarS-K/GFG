class Solution {
  public:
    int solve(vector<int>&arr , int i, int sum , vector<vector<int>>&dp){
        if(sum == 0)    return 1;
        if(sum < 0 || i >= arr.size()) return 0;
        if(dp[i][sum] != -1)    return dp[i][sum];
        
        int inc = solve(arr , i , sum - arr[i] , dp);
        int exc = solve(arr , i+1 , sum , dp);
        
        return dp[i][sum] = inc + exc;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>>dp(n+1 , vector<int>(sum+1 , -1));
        
        return solve(coins , 0, sum ,dp);
    }
};