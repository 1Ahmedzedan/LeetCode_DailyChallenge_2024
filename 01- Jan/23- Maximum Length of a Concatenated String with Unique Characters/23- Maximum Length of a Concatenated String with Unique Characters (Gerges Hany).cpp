#define sz(s) int(s.size())  
#define all(vec)  vec.begin(),  vec.end()
class Solution {
    
    int n;
    vector < string > vec;
    bool is_good(string& s){
        set < char > st(all(s));
        return sz(s) == sz(st);
    }

    int ans = 0;
    int rec(int Idx, string str){
        if (!is_good(str)) return 0;
        if(Idx >= n) {
            if (is_good(str)) ans = max(ans, (int)str.size());
            return 0;
        }
        int ret = 0;
        ret += rec(Idx + 1, str + vec[Idx]);
        ret += rec(Idx + 1, str);
        return ret;
    }
        
public:
    int maxLength(vector<string>& arr) {
        vec = arr; n = sz(arr);
        rec(0, "");
        return ans;
    }
};
