class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& x) {
       
       int n = x.size();
       vector < vector < int > > ans;
       map < int, bool > out_vis, in_vis;
       for (int i = 0; i < n; i++){
           in_vis.clear();
           vector < int > add;
           for (int j = 0; j < n; j++){
              if (!in_vis[x[j]] and !out_vis[j]){
                  add.push_back(x[j]);
                  in_vis[x[j]] = out_vis[j] = true;
              }
           }
           if (add.size()) ans.push_back(add);
       }
       return ans;
    }
};