// author : Ahmed Zedan


// explain :
/*
    - approach : dp recursive

    if n = 4 
    if but 4 in index 0
    4 * * * that's mean exist (3 inverse pair)
    if but 4 in index 1
    * 4 * * that's mean exist (2 inverse pair)
    .
    .
    .
    if but 4 in index 3
    * * * 4 that's mean exist (0 inverse pair)

    so dp[n][k] = dp[n-1][k-0] + dp[n-1][k-1] + ... + dp[n-1][k-(n-1)]

*/

class Solution {
public:
    const int mod = 1e9+7 ; 
    int dp[1001][1001] ; 

    int rec(int n , int k){
        if(k<=0) return k==0 ; 
        int &ret = dp[n][k] ;
        if(~ret) return ret; 

        int ans = 0 ; 
        for(int i=0 ; i<n ; ++i){
            ans += rec(n-1 , k-i) ; 
            ans %= mod ; 
        } 

        return ret = ans ; 
    }


    int kInversePairs(int n, int k) {
        memset(dp , -1 , sizeof(dp)) ; 
        return rec(n , k) ; 
    }
};