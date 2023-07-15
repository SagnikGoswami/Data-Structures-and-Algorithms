#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//Binary string have to delete 1 element tell the max consecutive 1 chain
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //state=count of 0 
        //invalid state=count of 0 more than 1
        //as 1 element delete must so subarray size will be end-start
        int n=nums.size();
        int startInd=0,count0=0,longestSubarr=0;
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt end index
            count0=count0+(nums[endInd]==0);
            //Now jb tak window invalid we keep removing the state wrt start of the window
            while(count0>1){
                count0=count0-(nums[startInd]==0);
                startInd++;
            }
            int subarrSize=endInd-startInd;//as deleted 1 element
            longestSubarr=max(longestSubarr,subarrSize);
        }
        return longestSubarr;
    }
};