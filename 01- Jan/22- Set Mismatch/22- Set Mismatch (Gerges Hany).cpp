class Solution {
public:
    vector<int> findErrorNums(vector< int >& nums) {
      int duplicated = 0, missing = 0;
      for (auto& i: nums) duplicated ^= i;
      set < int > st(nums.begin(), nums.end());
      for (int i = 1; i <= nums.size(); i++) missing ^= i; 
      for (auto& i: st) duplicated ^= i, missing ^= i;
      return {duplicated, missing};
    }
};

