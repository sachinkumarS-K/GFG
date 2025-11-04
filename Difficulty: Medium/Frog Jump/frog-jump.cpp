class Solution {
  public:
    int solve(vector<int>&arr , int i , vector<int>&dp){
        if(i >= arr.size()-1)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int one = INT_MAX , two = INT_MAX;
        if (i + 1 < arr.size())
            one = abs(arr[i] - arr[i + 1]) + solve(arr, i + 1, dp);

        if (i + 2 < arr.size())
            two = abs(arr[i] - arr[i + 2]) + solve(arr, i + 2, dp);

        return dp[i] = min(one, two);
    }
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size() , -1);
       return solve(height, 0, dp);
    }
};