class Solution {
public:
    int kInversePairs(int n, int k) {
       
       int mod = 1e9 + 7;
       int dp[n + 5][k + 5];
       memset(dp, -1, sizeof(dp));
       
       function < int(int, int) > f = [&](int idx, int kth){
          if (!kth) return 1;
          if (kth < 0 or idx <= 0) return 0;

          if (~dp[idx][kth]) return dp[idx][kth];

          long long ans = (f(idx - 1, kth) + f(idx, kth - 1)) % mod;
          ans -= f(idx - 1, kth - idx);
          return dp[idx][kth] = (ans + mod) % mod;  
       };  

       return f(n, k);
    }
};
