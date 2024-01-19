// author : ahmed zedan

/*
    - dp iterative
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size() ; 
        vector<vector<int>> dp (n+5,vector<int>(n+5,0)) ; 

        dp[0] = matrix[0] ; // base state
        
        // to check cell exist in matrix or not
        auto valid = [&](int i , int j) -> bool{
            return i>=0 && i<n && j>=0 && j<n ; 
        };

        for(int i=1 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                int r = INT_MAX , dl = INT_MAX , dr = INT_MAX;
                if(valid(i-1 , j)) r = dp[i-1][j] ; 
                if(valid(i-1 , j+1)) dl = dp[i-1][j+1] ; 
                if(valid(i-1 , j-1)) dr = dp[i-1][j-1] ; 
                dp[i][j] = matrix[i][j] + min({r , dl , dr}) ; 
            }
        }

        // minimize sum start from each cell in first row
        int ans=INT_MAX ; 
        for(int i=0 ; i<n ; i++){
            ans = min(ans,dp[n-1][i]) ; 
        }
        return ans ; 
    }
};