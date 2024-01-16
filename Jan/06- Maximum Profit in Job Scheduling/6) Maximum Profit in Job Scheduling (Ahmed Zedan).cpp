// author : Ahmed Zedan

/*
    - solve problem by binary search and memozation dp
    - using dp to get max profit
    - using binary search to get next job can do from current job
    - time complexity : O(nlog(n)) , space complexity : O(n)
*/


class Solution {
public:
    struct Job {
        int start , end , profit ; 
        Job(int start , int end , int profit){
            this->start = start ; 
            this->end = end ; 
            this->profit = profit ; 
        }
    };
    int n ;

    vector<Job> jobs ;
    vector<int> dp ;  

    //function to get next job from another end time another job
    int findNextJop(int endTime){
        int l=0 , r=n-1 , idx = n ; 
        while(l<=r){
            int m = l+(r-l)/2 ;
            if(jobs[m].start >= endTime){
                r=m-1 ; 
                idx = m ; 
            }
            else{
                l = m+1 ; 
            }
        }

        return idx ; 
    }

    // recursive function
    int maxProfit(int i = 0){
        if(i>=n) return 0 ; 

        // base case
        if(dp[i]!=-1) return dp[i] ; 

        // find next job can take if take current (by binary search)
        int nextJob = findNextJop(jobs[i].end) ; 
        
        // try take or leaf job to get maximum profit in all time
        int take = jobs[i].profit+maxProfit(nextJob) ; 
        int leaf = maxProfit(i+1) ; 

        return dp[i] = max(take , leaf) ;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size() ; 

        // add jobs to new Job vector
        for(int i=0 ; i<n ; ++i){
            Job newJop(startTime[i] , endTime[i] , profit[i]) ; 
            jobs.push_back(newJop) ; 
        }

        // sort data by start time
        sort(jobs.begin() , jobs.end() , [&](Job &lhs , Job &rhs){
            return lhs.start < rhs.start ; 
        }) ; 

        // memozation vector 
        dp = vector<int> (n+1 , -1) ; 

        return maxProfit() ;
    }
};