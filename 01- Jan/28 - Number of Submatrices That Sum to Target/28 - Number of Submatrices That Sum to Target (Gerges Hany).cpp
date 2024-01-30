class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int n = matrix.size(), m = matrix[0].size();
      vector < vector < int > > p(n + 1, vector < int > (m + 1));
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
      }

      function < int(int, int, int, int) > get = [&](int x1, int y1, int x2, int y2) {
        return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
      };

      int ans = 0;
      for (int x1 = 1; x1 <= n; ++x1) {
        for (int x2 = x1; x2 <= n; ++x2) {
          unordered_map < int, int > mp;
          mp[0] = 1;
          for (int y2 = 1; y2 <= m; ++y2) {
            int sum = get(x1, 1, x2, y2);
            ans += mp[sum - target];
            ++mp[sum];
          }
        }
      }

      return ans;
    }
};
