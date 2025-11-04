// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int>&arr , int idx , vector<int>&dp){
        if(idx >= arr.size())
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int pick = arr[idx] + solve(arr , idx+2 , dp);
        int notPick =  solve(arr , idx+1 , dp);
        
        return dp[idx] =  max(pick , notPick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size() , -1);
        return solve(arr , 0 , dp);
    }
};