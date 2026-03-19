class Solution {
  public:
    int solve(int a, int b, string &str1, string &str2, vector<vector<int>> &dp) {
        if (a == 0 || b == 0) return 0;

        if (dp[a][b] != -1) return dp[a][b];

        if (str1[a-1] == str2[b-1])
            return dp[a][b] = 1 + solve(a-1, b-1, str1, str2, dp);
        else
            return dp[a][b] = 0;
    }

    int longCommSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve(n1, n2, s1, s2, dp);
        int ans = 0;
        for(int i = n1 ; i>= 0 ; i--){
            for(int j = n2 ; j >= 0 ; j--){
                ans = max(ans , solve(i,j,s1,s2,dp));
            }
        }
        return ans;
    }
};