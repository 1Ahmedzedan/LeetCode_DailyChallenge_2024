class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map < int, bool > occ;
        sort(arr.begin(), arr.end());
        
        int cnt = 1;
        for (int i = 1; i < arr.size(); i++){
           if (arr[i] == arr[i - 1]) ++cnt;
           else{
               if (occ.count(cnt)) return false;
               occ[cnt] = true;
               cnt = 1;
           }
        }

        return !occ.count(cnt);
    }
};
