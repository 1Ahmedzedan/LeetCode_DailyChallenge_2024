// author : Ahmed Zedan

/*
    - solve problem with dynamic programming
    - count how many subsequence end with index (i)
    - time complex : O(n^2)
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size() , ans = 0 ; 
        map<pair<long long,long long> , long long> dp ; 

        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<i ; ++j ){
                long long diff = 1LL*nums[i] - nums[j] ; 
                dp[{i,diff}] += 1+dp[{j,diff}] ;
                ans += dp[{j,diff}] ; 
            }
        }

        return ans  ; 

    }
};