class Solution {
public:
    int rob(vector<int>& a) {
       const int N = 105, n = a.size();

       int dp[N]{};
       dp[0] = a[0];
       dp[1] = (n > 1 ? max(a[0], a[1]) : 0);
       
       for (int i = 2; i < n; i++){
           dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
       }

       return dp[n - 1];
    }
};
