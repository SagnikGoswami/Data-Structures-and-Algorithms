#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//Binary Subarray count subarray sum=goal
class Solution {
private:
    int atmost(vector<int> &nums,int goal,int n){
        if(goal<0) return 0;//as agar goal=0 tha aur goal-1 call toh dikkat hence as negative sum can't achieve so 0
        int startInd=0,count=0,sum=0;
        for(int endInd=0;endInd<n;endInd++){
            sum=sum+nums[endInd];
            while(sum>goal){
                sum=sum-nums[startInd];
                startInd++;
            }
            count=count+(endInd-startInd+1);
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums,int goal){
        int n=nums.size();
        return atmost(nums,goal,n)-atmost(nums,goal-1,n);
    }
};