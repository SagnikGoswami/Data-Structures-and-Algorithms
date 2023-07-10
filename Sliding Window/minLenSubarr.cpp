//Need to find the min length of subarray which is >= target
//So, we explore all the subarray sum ending at a particular endIndex

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int minLen=INT_MAX;
    int n=nums.size();
    int startInd=0;
    long long subarrSum=0;
    int endInd=0;
    while(endInd<n){
        //Subarray ends at endInd so first we add the endInd value
        subarrSum=subarrSum+nums[endInd];
        //Now we update minLen
        while(startInd<=endInd and target<=subarrSum){
            //as target se badha tabhi while mei ghus so potential
            //candidate
            int lenSubarr=endInd-startInd+1;
            minLen=min(minLen,lenSubarr);
            subarrSum=subarrSum-nums[startInd];// startInd ko hata de
            //aur check ki more chota subarray ending at endInd
            //possible or not
            startInd++;
        }
        //at the end we would have the min length subarray ending at end
        //so update endInd
        endInd++;
    }
    if(minLen==INT_MAX) return 0;
    return minLen;
}

// Mistake made by me:
int minSubArrayLen(int target, vector<int>& nums) {
    int minLen=INT_MAX;
    int n=nums.size();
    int startInd=0;
    long long subarrSum=0;
    for(int endInd=0;endInd<n;endInd++){
        //Subarray is from start to end so we add end to the sum
        subarrSum=subarrSum+nums[startInd];
        if(subarrSum>=target){
            //subArray from start to end is a potential min len array
            //So we update minLen
            int lenSubarr=endInd-startInd+1;
            minLen=min(minLen,lenSubarr);
            subarrSum-=nums[startInd];
            startInd++;
        }
    }
    // Agar endInd out of bound means start ke aage koi subarray
    // nahi mila jiska sum >= target
}
//above method not work as as soon as we reach an end>=target,
//we need to check the minLen subarray ending at the endInd
//So , we update the start till sum doesn't come out to be
//less than target so as to achieve the minLen subarr ending at endInd

//Binary Search se

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        //sums store the cummulative sum array
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};