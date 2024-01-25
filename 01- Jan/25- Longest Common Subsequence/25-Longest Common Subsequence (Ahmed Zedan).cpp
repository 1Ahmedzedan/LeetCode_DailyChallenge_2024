// author : Ahmed Zedan

// explain : 

/*
    - approach : dp recursive 
    - can try move to next char in text1 and keep in current char in text2 or reverse
    if current char in text1 and text2 try take this char in a common subsequance
*/

// class Solution {
// public:
//     int n , m ; 
//     vector<vector<int>> dp ; 
//     string s1 , s2 ; 

//     int rec(int i , int j){
//         if(i>=n || j>=m) return 0 ; 

//         int &ret = dp[i][j] ; 

//         if(~ret) return ret ;  

//         int call1 = rec(i+1 , j) ; 
//         int call2 = rec(i , j+1) ; 
//         int call3 = (s1[i]==s2[j])+rec(i+1 , j+1) ;

//         return ret = max({call1 , call2 , call3}) ;  
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         s1 = text1 ; 
//         s2 = text2 ; 
//         n = text1.size() , m = text2.size() ; 
//         dp = vector<vector<int>> (n+1 , vector<int>(m+1 , -1)) ; 

//         return rec(0 , 0) ; 

//     }
// };


// ==============================================================================================

// explain :

/*
    - approach dp iterative
*/


// class Solution {
// public:

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size() , m = text2.size() ; 
//         vector<vector<int>> dp (n+1 , vector<int>(m+1 , 0)) ; 

//         for(int i=1 ; i<=n ; ++i){
//             for(int j=1 ; j<=m ; ++j){
//                 dp[i][j] = max({dp[i-1][j] , dp[i][j-1] , (text1[i-1]==text2[j-1])+dp[i-1][j-1]}) ;
//             }
//         }

//         return dp[n][m] ; 

//     }

// };