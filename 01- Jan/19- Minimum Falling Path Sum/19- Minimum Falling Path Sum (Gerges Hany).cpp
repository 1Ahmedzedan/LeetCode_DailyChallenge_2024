class Solution {
public:
    
    int n;
    int dp[105][105];
    vector<vector<int>> a;
    int get_min_sum(int i, int j){
        if (i == n) return 0;
        if (dp[i][j] != 105) return dp[i][j];
        int ans = 1e9;
        for (int k = -1; k <= 1; k++){
            if (j + k >= 0 && j + k < n){
                ans = min(ans, get_min_sum(i + 1, j + k) + a[i][j]);
            }
        }
        return dp[i][j] = ans;
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        a = matrix;
        n = matrix.size();
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                dp[i][j] = 105;
            }
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++){
            ans = min(ans, get_min_sum(0, i));
        }
        return ans;
    }
};
