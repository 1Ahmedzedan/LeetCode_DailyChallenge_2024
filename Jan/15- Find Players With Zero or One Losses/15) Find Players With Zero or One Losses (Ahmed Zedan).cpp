// author : Ahmed Zedan


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>v1,v2 ; 
        map<int,int>mp ; 

        for(auto v : matches){
            mp[v[1]]++ ; 
            if(!mp[v[0]]) mp[v[0]] = 0 ; 
        }

        for(auto &[f,s]:mp){
            if(!s) v1.push_back(f) ; 
            if(s==1) v2.push_back(f) ; 
        }
        
        sort(v1.begin(),v1.end()) ;
        sort(v2.begin(),v2.end()) ; 
        return {v1,v2} ; 
    }
};