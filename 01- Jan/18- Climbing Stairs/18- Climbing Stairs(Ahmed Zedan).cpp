// author : Ahmed Zedan

class Solution {
public:
    //  n = 45 
    vector<int> dp ; 
    int rec(int x){
        if(x<=2) return x ; 
        int &ret = dp[x] ; 
        if(~ret) return ret ; 
        return ret = rec(x-1)+rec(x-2) ;  

    }

    int climbStairs(int n) {
        dp = vector<int>(n+5,-1) ; 
        return rec(n) ;  
    }
};