// author : Ahmed Zedan

/*
    - number of conected n leaser and m leaser = n*m
    - time complexity : O(n*m) , space complexity : O(1) 
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long prev = 0 , ans = 0 ; 

        for(auto &s : bank){
            long long cnt = 0 ; 
            for(auto &i : s) cnt += (i == '1') ; 
            ans += (cnt * prev) ; 
            if(cnt) prev = cnt ; 
        }

        return ans ; 
    }
};