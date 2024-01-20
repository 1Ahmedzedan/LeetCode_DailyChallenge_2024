class Solution {
public:
    bool halvesAreAlike(string s) {
        
        auto is_vowel = [&](char c){
            c = tolower(c);
          return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };
        
        auto count = [&](string s){
          int cnt = 0;
          for (auto & i: s) cnt += is_vowel(i);
          return cnt;
        };
       
        return (s.size() & 1 ^ 1 && count(s.substr(0, s.size() / 2)) == count(s.substr(s.size() / 2)));
    }
};
