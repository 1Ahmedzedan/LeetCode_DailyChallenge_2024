class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int ans = 0;
       sort(g.begin(), g.end());
       sort(s.begin(), s.end());
       
       int j = 0;
       for (int i = 0; i < g.size(); i++){
           while(j < s.size() and s[j] < g[i]) j++;
           if (j < s.size()) ans++, j++;
       }
       return ans;
    }
};