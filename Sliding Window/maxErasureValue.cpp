#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//can erase subarray(all unique elements) get score=sum of elements
//max score can get by erase exactly 1 subarray
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //state = count
        //invalid state = count[end number]>1

        int startInd=0,n=nums.size(),maxScore=0,windowScore;
        unordered_map<int,int> count;
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt ending number
            int endNum=nums[endInd];
            windowScore=windowScore+endNum;
            count[endNum]++;
            //Now if the state becomes invalid we remove start from state
            //keep removing start till state doesn't become valid
            while(count[endNum]>1){
                int startNum=nums[startInd];
                count[startNum]--;
                windowScore=windowScore-startNum;
                startInd++;
            }
            maxScore=max(maxScore,windowScore);
        }
        return maxScore;
    }
};