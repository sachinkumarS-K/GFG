class Solution {
  public:

    int solve(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n == 1) return 2;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int countConsec(int n) {
        vector<int> dp(n + 1, -1);

        long long total = 1LL << n;      
        long long valid = solve(n, dp);  

        return total - valid;
    }
};
