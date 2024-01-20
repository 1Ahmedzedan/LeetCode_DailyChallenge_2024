// author : Ahmed Zedan

/*
    - solve problem using binary search 
    - if next number in array (nums) > last element in LIS add to LIS
    - else get index need to update by current element using lower_bound algorithm
    - time complexity : O(nlog(n)) , space complexity : O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans ; 
        int n = nums.size() ; 
        ans.push_back(nums[0]) ; 
        for(int i=0 ; i<n ; i++){
            if(nums[i]>ans.back()) ans.push_back(nums[i]) ; 
            else{
                int idx = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin() ; 
                ans[idx] = nums[i] ;
            }
        }
        return ans.size() ; 
    }
};