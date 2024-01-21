// author : Ahmed Zedan

// recursive solution 

// class Solution {
// public:
//     vector<int>dp ; 
//     vector<int>v ;
//     int sz ;  
//     int rec(int i=0){
//         if(i>=sz) return 0 ; 
//         int &ret =  dp[i] ;
//         if(~ret) return ret ; 
//         return ret = max(rec(i+1),v[i]+rec(i+2)) ; 
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size() ;
//         dp = vector<int>(n+5,-1) ; 
//         v = nums ; 
//         sz = n ; 
//         return rec() ; 
//     }
// };

// iterative solution

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size() ;
//         vector<int> dp(n+5,0) ; 
        
//         dp[0] = nums[0] ; 
//         if(n>1) dp[1] = max(nums[0] , nums[1]) ; 

//         for(int i=2 ; i<n ; ++i){
//             dp[i] = max(dp[i-1] , dp[i-2]+nums[i]) ; 
//         }

//         return dp[n-1] ; 
//     }
// };
