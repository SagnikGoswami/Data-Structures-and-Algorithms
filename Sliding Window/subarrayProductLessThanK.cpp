//Count subarray with product strictly less than k
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums,int k){
        //state = product of all elements in wiindow
        //invalid state = windowProduct>=k
        int startInd=0,count=0,windowProduct=1;
        int n=nums.size();
        for(int endInd=0;endInd<n;endInd++){
            //update state using the ending element
            windowProduct=windowProduct*nums[endInd];
            //Now jab tak state is invalid we will remove the state wrt startInd
            while(startInd<=endInd and windowProduct>=k){
                //pehla check lagana padha as maybe end index is himself>=k so start exceeded the endInd
                windowProduct=windowProduct/nums[startInd];
                startInd++;
            }
            //Now we will have end-start+1 new subarrays ending at endInd so count all those as 
            //start to end is valid subarray so all those will also be valid subarrays
            count=count+(endInd-startInd+1);
        }
        return count;
    }
};