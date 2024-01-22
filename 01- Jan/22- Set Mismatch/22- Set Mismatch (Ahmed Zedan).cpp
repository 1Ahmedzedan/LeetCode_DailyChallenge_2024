// author : Ahmed Zedan

/*
    - time complexity : O(n) , space complexity : O(n)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() ,  sumWithoutDublicate = 0 , sumWithDublicate=0 ;

        int sumOfOrginalArray = n*(n+1)/2 ; 

        for(auto i : nums) sumWithDublicate+=i ; 

        set<int>st(nums.begin(),nums.end()) ; 

        for(auto &i : st) sumWithoutDublicate +=i ;
        int misNumber = sumOfOrginalArray - sumWithoutDublicate  , dublicateNumber = sumWithDublicate - sumWithoutDublicate ;


        return {dublicateNumber,misNumber} ; 
    }
};