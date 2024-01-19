class Solution {
public:
    int minSteps(string s, string t) {

        map < int, int > mp_s, mp_t;
        for (int i = 0; i < s.size(); i++) mp_s[s[i]]++, mp_t[t[i]]++;
        
        int ans = 0;
        for (auto & [i, occ]: mp_s) if (occ > mp_t[i]) ans += occ - mp_t[i];
        return ans;
    }    
        
};
