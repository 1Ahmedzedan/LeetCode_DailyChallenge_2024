// author : Ahmed Zedan

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp ; 
        set <int> st ;

        // get number of occurrences for each element 
        for(auto &i : arr) mp[i]++ ; 
        // get number of unique occurrences
        for(auto &[f , s] : mp) st.insert(s);

        // check if number of unique occurrences = number of unique element in (arr)
        return st.size() == mp.size() ; 
    }
};