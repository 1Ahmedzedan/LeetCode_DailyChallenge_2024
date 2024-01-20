class Solution {
#define ll long long   
#define sz(s) s.size() 
#define all(a) a.begin(), a.end()

public:
    struct node{
        int s, e, p;
        bool operator < (const node &b) const{
            return s == b.s ? e < b.e : s < b.s; 
        }
    };

    vector < ll > dp;      
    vector < node > cost;
    ll rec(int idx){
        if (idx == sz(cost)) return 0;
        ll &ret = dp[idx];
        if (~ret) return ret;
        ret = rec(idx + 1);
        int nxt = upper_bound(all(cost), node{cost[idx].e, 0, 0}) - cost.begin();
        ret = max(ret, rec(nxt) + cost[idx].p);
        return ret;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for (int i = 0; i < profit.size(); i++) 
            cost.push_back({startTime[i], endTime[i], profit[i]});
     
        sort(all(cost)); 
        dp.resize(sz(cost) + 1, -1);
        return rec(0);
    }
};
