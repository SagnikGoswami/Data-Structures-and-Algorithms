//n jobs and n person need to give 1 job to each person find min cost
//to distribute each jobs cost[i][j] means giving jth job to ith person ka cost

//Constraints 1<=n<=21
//So bitmask DP ki feel as need to try all possible combination of job
//with person and also n is very less

//set of person is represented by mask ie.
//{P0,P1,P2,P5,P6} are the remaining person available means (n=7)
//mask will be 0 1 1 0 0 1 1 1
//             7 6 5 4 3 2 1 0 <-bit number

//So recurrence is dp[i][mask]=min(cost[p][i]+dp[i+1][mask with p as off])
//as assigning pth person with job(can only if p is free)

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution{
    int getMinCost(int startJob,int mask,vector<vector<int>> &cost,int n,vector<vector<int>> &dp){
        if(startJob==n){
            //means no jobs are there so cost taken will be 0
            return 0;
        }
        //Now for all the persons which are free(bit is set)
        //we try giving starting job to them and remaining can be calculated
        //by recursion
        if(dp[startJob][mask]!=-1) return dp[startJob][mask];
        int minCost=INT_MAX;
        for(int personNumber=0;personNumber<n;personNumber++){
            if(mask&(1<<personNumber)){
                //means that personNumber walla bit is set ie. 
                //yeh person is free
                int costRequired=cost[personNumber][startJob]+getMinCost(startJob+1,mask&(~(1<<personNumber)),cost,n,dp);
                //mask&(~(1<<personNumber)) as turn off krna tha woh bit
                minCost=min(minCost,costRequired);
            }
        }
        return dp[startJob][mask]=minCost;
    }
public:
    int minimumCost(int n,vector<vector<int>> &cost){
        int startJob=0;
        //Initially mask will be all n bits are 1 ie.
        //all persons are free so (1<<n) size ka
        vector<vector<int>> dp(n,vector<int>((1<<n),-1));
        int mask=(1<<n)-1;//tabhi 64 ka constraint as tabhi long long mei fit ho
        int minCost=getMinCost(startJob,mask,cost,n,dp);
        return minCost;
    }
};