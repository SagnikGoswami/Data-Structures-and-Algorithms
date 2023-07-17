//Logic is : nums[i]-k to nums[i]+k interval make so [4,6,1,2] and k=2 hence
//wrt 4           2 3 4 5 6
//wrt 6               4 5 6 7 8
//wrt 1    -1 0 1 2 3
//wrt 2       0 1 2 3 4 
//So clearly 4 comes 3 time in intersection so can make 3 numbers equal to 4
//also 2 and 3 can be so ranges given L to R and we need to find the max frequent element
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//We are given an array aur can change any element to ele-k to ele+k now tell
//the max size subsequence with the same elements
class Solution {
private:
    int getMaxFreq(vector<pair<int,int>> &intervals){
        //returns the element having max freq
        map<int,int> prefixArr;
        for(auto it : intervals){
            int lowerLimit=it.first;
            int upperLimit=it.second;
            prefixArr[lowerLimit]++;
            prefixArr[upperLimit+1]--;
        }
        int maxFreq=0,currFreq=0;
        for(auto it : prefixArr){
            currFreq+=it.second;
            maxFreq=max(maxFreq,currFreq);
        }
        return maxFreq;
    }
public:
    int maximumBeauty(vector<int>& nums,int k){
        int n=nums.size();
        vector<pair<int,int>> intervals;
        for(int i=0;i<n;i++){
            int lowerLimit=nums[i]-k;
            int upperLimit=nums[i]+k;
            intervals.push_back({lowerLimit,upperLimit});
        }
        return getMaxFreq(intervals);
    }
};