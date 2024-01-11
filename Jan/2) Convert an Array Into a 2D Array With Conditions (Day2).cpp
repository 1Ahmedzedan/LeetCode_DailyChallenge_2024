// author : Ahmed Zedan

/*
    - get frequency all element in array (nums)
    - get maximum of frequent to determine number of rows
    - add each frequency of same element in new row 
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size() ; 
        map<int , int> mp ; 
        int mxFreq = 0 ; 
        
        for(auto &i : nums){
            mp[i]++ ; 
            mxFreq = max(mxFreq , mp[i]) ; 
        }

        vector<vector<int>> ans(mxFreq) ; 
        for(auto &[f,s] : mp){
            for(int i=0 ; i<s ; ++i){
                ans[i].push_back(f) ; 
            }
        }

        return ans ; 
    }
};