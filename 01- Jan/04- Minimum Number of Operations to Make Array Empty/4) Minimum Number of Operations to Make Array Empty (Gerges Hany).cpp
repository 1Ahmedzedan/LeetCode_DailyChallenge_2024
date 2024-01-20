class Solution {
public:
    int minOperations(vector<int>& nums) {
       map < int, int > f;
       for (auto & i: nums) ++f[i]; 
       
       int ans = 0;
       for (auto & [i, occ]: f){
           if (occ < 2) return -1;
           ans += (occ + 2) / 3;
       }
       return ans;
    }
};