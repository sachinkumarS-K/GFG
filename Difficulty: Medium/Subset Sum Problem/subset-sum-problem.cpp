class Solution {
  public:
    bool solve(int i , int sum , vector<int>&arr , vector<vector<int>>&dp){
        if(sum == 0)    return true;
        if(i >= arr.size() || sum < 0) return false;
        if(dp[i][sum] != -1)    return dp[i][sum];
        
        return dp[i][sum] = solve(i+1 , sum-arr[i] , arr ,dp) || solve(i+1,sum , arr ,dp);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(0 , sum , arr ,dp);
    }
};