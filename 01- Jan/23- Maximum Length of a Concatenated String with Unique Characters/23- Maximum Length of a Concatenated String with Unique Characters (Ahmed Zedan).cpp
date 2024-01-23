// author : Ahmed Zedan

/*
    - approach: dp 
    - each char in string (arr[i]) represent as bit 
    - in (vis) set all bits in (arr[i])
    - check exit duplicate in (arr[i]) by (or) bitwise operator
    - concatenated to string by (and) bitwise operator
*/


class Solution {

// to count number of (bit = 1) in number n
int countBits(int n){
    int bits = 0 ; 
    for(int i=0 ; i<31 ; ++i){
        if((n&1<<i)) bits ++ ; 
    }
    return bits ; 
}

public:
    int maxLength(vector<string>& arr) {
        int ans = 0 ; 
        vector <int> dp ; 
        dp.push_back(0) ; 

        for(auto &s : arr){
            int dup = 0 , vis = 0 ; 
            for(auto &c : s){
                int currBit = (1<<(c-'a')) ; // get power of two for char (c)
                dup |= (vis & currBit) ; // check if exist duplicated
                vis |= currBit ; // combine bits 

                if(dup>0) break ; 
            }
            
            if(dup > 0) continue ;

            int n = dp.size() ; 
            for(int i=0 ; i<n ; ++i){
                if((dp[i] & vis) > 0) continue ; 
                
                int comp = (dp[i]|vis) ; 

                dp.push_back(comp) ; 
        
                ans = max(ans , countBits(comp)) ; 
            }
        }

        return ans ; 
    }
};