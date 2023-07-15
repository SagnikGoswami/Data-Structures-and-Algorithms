#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//count subarray with k different numbers
class Solution {
private:
    int atmost(vector<int> &nums,int goal,int n){
        //count of subarrays with goal number of different intergers
        int startInd=0,count=0;
        unordered_map<int,int> numCount;//window mei kitne number kitne baar aa rha uska count rkh
        for(int endInd=0;endInd<n;endInd++){
            int endNum=nums[endInd];
            numCount[endNum]++;
            while(numCount.size()>goal){
                int startNum=nums[startInd];
                numCount[startNum]--;
                startInd++;
                if(numCount[startNum]==0) numCount.erase(startNum);
            }
            count=count+(endInd-startInd+1);
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums,int k){
        int n=nums.size();
        return atmost(nums,k,n)-atmost(nums,k-1,n);
    }
};