#include <iostream>
using namespace std;
#include <bits/stdc++.h>
long maximumSumSubarray(int k, vector<int> &arr , int n){
    int startInd=0,endInd=0;//startInd->endInd is our window
    long windowSum=0;//sum of all the elements in our window
    long maxSum=INT_MIN;
    while(endInd<n){
        //As last window woh jiska end index is n-1
        //utne hi windows consider krenge apan
        windowSum+=arr[endInd];
        int windowSize=endInd-startInd+1;
        if(windowSize<k){
            //means we need to add more elements
            //this is not a valid window so we don't update 
            //max sum
            endInd++;
        }
        else if(windowSize==k){
            //Once we have a window of size k we will maintain the
            //window size ie. starting of window element hata
            //and end walla add
            //Also update max as this is valid window
            maxSum=max(maxSum,windowSum);
            windowSum-=arr[startInd];//as start ko hata rhe
            startInd++,endInd++; //so that window size is maintained
        }
    }
    return maxSum;
}