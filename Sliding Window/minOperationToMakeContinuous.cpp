//Subarray with unique elements aur max-min=(n-1) aisa subarray 
//tell kitne min elements change st continuous
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
public:
    int minOperations(vector<int>& nums){
        //first we remove duplicates as surely they would be replaced by other number
        int n=nums.size();//store so that we can have a check how many start+(n-1) range tak
        sort(nums.begin(),nums.end());
        nums.erase(unique(begin(nums),end(nums)),end(nums));
        //pehle sort krlo so that window mei have an idea ki next ja toh greater element mil
        //max sized window in which numbers are in range startInd walla element se startElem+(n-1) tak
        //As then answer would be n-that window size as rest missing ko fill up
        int m=nums.size();//issi array mei iterate so length new walla take
        int maxWindowSize=0;
        int startInd=0;
        for(int endInd=0;endInd<m;endInd++){
            //Caclulations kuch nahi karna baas window size hi nikalna kyunki
            //Agar invalid hua start->end walla window ie. start+(n-1) range ke bahar chala gya new added endInd
            //then valid bana start ko increase kr
            while(nums[startInd]+n<=nums[endInd]) startInd++;
            //Now that we have start to end mei all in range start+(n-1){so sure becoz end index joh max tha whi aa gya
            //isiliye sort kiya tha}
            int windowSize=endInd-startInd+1;
            maxWindowSize=max(maxWindowSize,windowSize);
        }
        return n-maxWindowSize;
    }
};