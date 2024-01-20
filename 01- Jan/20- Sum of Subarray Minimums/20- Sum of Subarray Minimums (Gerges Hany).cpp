class Solution {
public:

    template < typename T = int > struct monotonic_stack{
    
        T n;
        vector < T > v;
        vector < T > ans;
        stack < pair < T, T > > st;
        
        monotonic_stack(vector < T > &v) : v(v) {
            n = v.size();
            ans = vector < T > (n);
        }
        
        // function to get the next smaller if no smaller element return n
        vector < T > next_smaller_element(){
            for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first >= v[i]) st.pop();
                ans[i] = (st.empty() ? n : st.top().second);
                st.push({v[i], i});
            }
            return ans;
        }
        
        // funtion to get the previous smaller if no smaller element return -1
        vector < T > prev_smaller_element(){
            for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > v[i]) st.pop();
                ans[i] = (st.empty() ? -1 : st.top().second);
                st.push({v[i], i});
            }
            return ans;
        }
    
    
    };

    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& a) {
        long long ans = 0;
        auto nxt_smaller = monotonic_stack < int > (a).next_smaller_element();
        auto prev_smaller = monotonic_stack < int > (a).prev_smaller_element();
  
        int n = a.size();
        for (int i = 0; i < n; i++){
            long long sub = abs(i - nxt_smaller[i]) * abs(i - prev_smaller[i]);
            ans += sub * a[i];
            ans %= mod;
        }

        return ans;
    }
};
