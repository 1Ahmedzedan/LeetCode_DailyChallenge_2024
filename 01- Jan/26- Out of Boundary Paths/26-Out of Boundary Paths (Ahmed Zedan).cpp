// author : Ahmed Zedan

// explain : 

/*
    - approach : dp recursive
*/

class Solution {
public:
    int dp[51][51][51] ; 
    int mod = 1e9 + 7 ; 
    vector<pair<int,int>> dir = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}} ; 

    int rec(int i , int j , int move , int n , int m){
        if(move<0) return 0 ; 
        if(i>=n || j>=m || i<0 || j<0) return 1 ; 

        int &ret = dp[i][j][move] ; 

        if(~ret) return ret ; 

        ret = 0 ; 
        for(auto &[x , y] : dir){
            ret =(ret%mod + rec(i+x , j+y , move-1 , n , m)%mod)%mod ; 
        }

        return ret%mod ; 
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp , -1 , sizeof(dp)) ; 
        return rec(startRow , startColumn , maxMove , m , n) ; 
    }
};
