// author : Ahmed Zedan

class Solution {
public:
    bool isVowels(char c){
        c = tolower(c) ; 
        return (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') ; 
    } 

    bool halvesAreAlike(string s) {
        int n = s.size() , cnt1 = 0 , cnt2 = 0 ; 
        for(int i=0 ; i<n ; ++i){
            if(isVowels(s[i])){
                (i>=n/2 ? cnt2++ : cnt1++) ;  
            }
        }
        return cnt1 == cnt2 ; 
    }

};