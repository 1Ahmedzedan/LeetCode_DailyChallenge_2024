class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        unordered_map<long, vector<int>> mp;
        vector < vector < int > > dp(n, vector < int > (n, 0));

        for (int i = 0; i < n; i++) {
            if (!mp.count(a[i])) mp[a[i]] = vector < int > ();
            mp[a[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j < n; j++){
                long long d = 2LL * a[i] - a[j];
                if (mp.count(d)){
                    for (auto & k: mp[d]){
                        if (k < i) dp[i][j] += dp[k][i] + 1;
                        else break;
                    }
                }
               ans += dp[i][j];
            }
        }
        return ans;
    }
};
