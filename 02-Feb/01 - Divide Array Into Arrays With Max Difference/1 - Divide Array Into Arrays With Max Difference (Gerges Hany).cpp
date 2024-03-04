class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       
       vector < int > a;
       int x = 0, n = nums.size();      
       sort(nums.begin(), nums.end());
       vector < vector < int > > ans;
       
       for (int i = 0; i < n; i++) {
          if (a.empty() or (nums[i] - a.front() <= k)) {
               a.push_back(nums[i]);
          } 
          else{
            if (a.size() < 3) return {};
          }
          if (a.size() == 3) {
            ans.push_back(a);
            a.clear();
          }
       }
      return ans;
    }
};
