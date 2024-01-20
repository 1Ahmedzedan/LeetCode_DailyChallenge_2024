//author : Ahmed Zedan

/*
    to be two string closed if (word1) contain char x should string     (word2) contain's same char and frequant each element in string (word1) equal frequent each char in string (word2)
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>mp1 ; 
        map<char,int>mp2 ; 
        vector<int>freq1,freq2 ; 
        for(auto &i:word1) mp1[i]++;
        for(auto &i:word2) mp2[i]++;

        for(char i='a' ; i<='z' ; i++){
            if(mp1[i]&&mp2[i]){
                freq1.push_back(mp1[i]) ;
                freq2.push_back(mp2[i]) ;
            }
            else if(!mp1[i]&&!mp2[i]) continue ; 
            else return false ; 
        }
        
        sort(freq1.begin(),freq1.end()) ;
        sort(freq2.begin(),freq2.end()) ; 
        return freq1==freq2 ; 
    }
};