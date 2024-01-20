class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map < int, int > lost;
        for (auto & x: matches){
            ++lost[x[1]];
        }

        vector < int > x1, x2;
        for (auto & x: matches){
            if (!lost[x[0]]) x1.push_back(x[0]);
            if (lost[x[1]] == 1) x2.push_back(x[1]);
        }

        auto fix = [&](vector < int >& x){
            sort(x.begin(), x.end());
            auto it = unique(x.begin(), x.end());
            x.resize(distance(x.begin(), it));
        };

        fix(x1), fix(x2);
        vector < vector < int > > ans = {x1, x2};
        return ans;    
    }
};
