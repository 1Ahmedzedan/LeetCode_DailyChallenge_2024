// author : Ahmed Zedan

// time complexity : O(n) , space complexity : O(n)

#define ll long long
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size() , mod = 1e9+7; 

        // store index previous smaller or equal element in (left) and next smaller or equal element (right)
        vector<int> left(n , -1) , right(n , n) ;
        stack<int> stk ; 

        // monotonic stack approach
        for(int i = 0 ; i < n ; ++i){
            while(!stk.empty() && arr[stk.top()] > arr[i]) stk.pop() ; 
            if(!stk.empty()) left[i] = stk.top() ; 
            stk.push(i) ; 
        }
        
        stk = stack<int>() ; 

        for(int i = n-1 ; i >= 0 ; --i){
            while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop() ; 
            if(!stk.empty()) right[i] = stk.top() ; 
            stk.push(i) ; 
        }

        ll sum = 0 ; 

        // get sum
        for(int i = 0 ; i < n ; ++i){
            sum += 1LL * (i-left[i]) * (right[i]-i) * arr[i] ; 
            sum %= mod ;  
        }

        return sum ;

    }
};