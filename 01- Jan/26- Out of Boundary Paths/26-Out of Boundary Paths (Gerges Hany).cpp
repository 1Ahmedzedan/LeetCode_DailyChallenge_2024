class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
      const int mod = 1e9 + 7;  
      int dp[m + 1][n + 1][maxMove + 1];
      // dp[i][j][maxMove] = number of ways to reach (i, j) in maxMove moves
      memset(dp, -1, sizeof(dp));
      function < bool(int, int) > valid = [&](int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
      };

      int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
      function < int(int, int, int) > count = [&](int i, int j, int k){
        if (k < 0) return 0;
        if (!valid(i, j)) return 1;

        int &ans = dp[i][j][k];
        if (~ans) return ans;

        ans = 0;
        for (int d = 0; d < 4; ++d) {
          int x = i + dx[d], y = j + dy[d];
          ans = (ans + count(x, y, k - 1)) % mod;
        }

        return ans;
      };

      return count(sr, sc, maxMove);
    }
};
