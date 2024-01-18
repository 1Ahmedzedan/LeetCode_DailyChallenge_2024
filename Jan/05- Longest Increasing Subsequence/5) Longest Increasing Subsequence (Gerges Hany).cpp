class Solution {
#define sz(s) (int)(s.size())  
#define all(vec)  vec.begin(),  vec.end()
public:
    int lengthOfLIS(vector<int>& nums) {
        vector < int > dp;
        for (auto &x : nums) {
            auto it = lower_bound(all(dp), x);
            if (it == dp.end()) dp.push_back(x);
            else *it = x;
        }
        return sz(dp);
    }
};
