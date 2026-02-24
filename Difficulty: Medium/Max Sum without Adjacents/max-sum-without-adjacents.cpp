// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int>&arr , int i , vector<int>&dp){
        if(i >= arr.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int inc = arr[i] + solve(arr , i+2 , dp);
        int exc = solve(arr , i+1 , dp);
        return dp[i] = max(inc , exc);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size() , -1);
        return solve(arr , 0 , dp);
    }
};