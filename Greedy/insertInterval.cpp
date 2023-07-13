//Insert kro new interval such that merged intervals hi rhe, given intervals
//in sorted order of starting of range


#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Pehle woh saare intervals jinke end is less than new interval ka start
        //pakke se woh not overlap with new interval
        int n=intervals.size();
        int newIntervalStart=newInterval[0];
        int newIntervalEnd=newInterval[1];
        int currInd=0;
        vector<vector<int>> ans;
        while(currInd<n and intervals[currInd][1]<newIntervalStart){
            ans.push_back(intervals[currInd]);
            currInd++;
        }
        //Now if the newInterval's end index is greater than current interval's start then can merge both
        while(currInd<n and intervals[currInd][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[currInd][0]);
            newInterval[1]=max(newInterval[1],intervals[currInd][1]);
            currInd++;
        }
        ans.push_back(newInterval);
        //Now remaining jiska start is greater than end of interval
        while(currInd<n){
            ans.push_back(intervals[currInd]);
            currInd++;
        }
        return ans;
    }
};