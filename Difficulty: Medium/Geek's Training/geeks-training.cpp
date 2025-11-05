class Solution {
  public:
    int solve(int i , int prev , vector<vector<int>>& arr , vector<vector<int>>&dp){
        if(i >= arr.size()) 
            return 0;
            
        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];
             
        int maxPoints = 0;
        for(int j = 0 ; j < arr[0].size() ; j++){
            if(j != prev){
                int points = arr[i][j] + solve(i + 1, j, arr , dp);
                maxPoints = max(maxPoints, points);
            }
        }
        return dp[i][prev+1] = maxPoints;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0 , -1 , arr , dp);
    }
};