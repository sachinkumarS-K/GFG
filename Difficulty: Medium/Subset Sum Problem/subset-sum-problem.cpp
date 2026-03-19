class Solution {
  public:
    // bool solve(int i , int sum , vector<int>&arr , vector<vector<int>>&dp){
    //     if(sum == 0)    return true;
    //     if(i >= arr.size() || sum < 0) return false;
    //     if(dp[i][sum] != -1)    return dp[i][sum];
        
    //     return dp[i][sum] = solve(i+1 , sum-arr[i] , arr ,dp) || solve(i+1,sum , arr ,dp);
    // }
    bool solveUsingTabulation(vector<int>&arr , int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
            
        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = 1 ; j <= sum ;j++){
                bool inc = false;
                if(j-arr[i] >= 0)
                    inc = dp[i+1][j-arr[i]];
                bool exc = dp[i+1][j];
                dp[i][j] = inc || exc ;
            }
        }
        return dp[0][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return solve(0 , sum , arr ,dp);
        return solveUsingTabulation(arr , sum);
    }
};