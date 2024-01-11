// author : Ahmed Zedan

/*
    - sort array (g) and array (s) 
    - get maximum number of content children by use pointers
    - (i) pointer to access array (g) , (j) pointer to access array (s)
    - if g[i] <= s[j] increase number of content children and move pointers (i and j)
    - if g[i]>s[j] move pointer (j)
    - time complexity : O(max(n,m)) and space complexity : O(1)
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end()) ; 
        sort(s.begin() , s.end()) ;

        int i=0 , j=0 , ans=0 ; 

        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                ans ++ ; 
                i++ , j++ ; 
            }
            else j++ ; 
        } 
        
        return ans ; 
    }
};