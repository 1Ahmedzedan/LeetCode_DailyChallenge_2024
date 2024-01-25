class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        function < int(int, int) > solve = [&](int i, int j){
           if (i == n or j == m) return 0;

           int& ret = dp[i][j];  
           if (~ret) return ret;
           
           if (s[i] == t[j]) return ret = 1 + solve(i + 1, j + 1);

           return ret = max(solve(i + 1, j), solve(i, j + 1));
        };

        return solve(0, 0);
    }
};
