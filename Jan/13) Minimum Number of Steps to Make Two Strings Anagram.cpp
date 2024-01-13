// author : Ahmed Zedan

class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp1 , mp2 ; 
        for(auto &i : s) mp1[i]++ ; 
        for(auto &j : t) mp2[j]++ ;

        int ans = 0 ; 
        for(auto &[i , freq] : mp1){
            if(freq > mp2[i]) ans += (freq - mp2[i]) ; 
        }

        return ans ; 
    }
};