// author : Ahmed Zedan

/*
    - get frequency of all element in array (nums)
    - we can't make array empty in one case if exist element appear once time only
    - minimum number of operation to remove all frequency of element x =  ceil(freq of x / 3) why? 
        - if((freq of x) % 3 == 0) we need only operation 2
        - if((freq of x) % 3 == 1) we need do opertion 1 twice time and remove remain frequent by operation 2
        - if((freq of x) % 3 == 2) we need do opertion 1 once time and remove remain frequent by operation 2 
    - time complexity : O(n) , space complexity : O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int , int> mp ; 
        for(auto &i : nums) mp[i]++ ; 
        int ans = 0 ; 

        for(auto &[f,s] : mp){
            if(s==1) return -1 ;
            
            ans += ((s+2)/3) ; // ceil(repeat/3)
        }

        return ans ; 
    }
};