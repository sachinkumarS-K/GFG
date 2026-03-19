class Solution {
  public:
    int solve(int i , int target , vector<int>&arr , vector<vector<int>>&dp){
        if(i == arr.size())   
            return (target == 0);
        if(dp[i][target] != -1) return dp[i][target];
        
        int inc = 0 ;
        if(target-arr[i] >= 0)
            inc = solve(i+1 , target-arr[i] , arr , dp);
        int exc = solve(i+1,target , arr , dp);
        
        return dp[i][target] = inc + exc ;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size() , vector<int>(target+1 , -1));
        return solve(0 , target , arr , dp);
    }
};