class Solution {
public:
    bool closeStrings(string s, string t) {
        
        if (s.size() != t.size()) return false;
        map < char, int > mp_s, mp_t;
        for (int i = 0; i < s.size(); i++) ++mp_s[s[i]], ++mp_t[t[i]];
        
        for (auto &x : mp_s) if (!mp_t.count(x.first)) return false;
        for (auto &x : mp_t) if (!mp_s.count(x.first)) return false;
  
        multiset < int > st_s, st_t;
        for (auto &x : mp_s) st_s.insert(x.second);
        for (auto &x : mp_t) st_t.insert(x.second);

        return st_s == st_t;
    }
};
