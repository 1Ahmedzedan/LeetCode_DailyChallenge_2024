class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        int x = 1;
        vector < int > ans;
        while(x < 9){
           int y = x++;
           long long tmp = 0;
           while(y <= 9) {
                tmp = (tmp * 10) + y++;
                if (tmp >= low and tmp <= high){
                    ans.push_back(tmp);
                }
           }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
