#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
    public:
    int lenOfLongSubarr(int arr[],int n,int k) 
    { 
        int startInd=0,endInd=0;
        int windowSum=0;//stores the sum of all numbers in window
        int maxLen=0;
        while(endInd<n){
            windowSum+=arr[endInd];
            //case 1
            if(windowSum<k) endInd++;
            //case 2
            else if(windowSum==k){
                //means start to end is a valid candidate
                int windowSize=endInd-startInd+1;
                maxLen=max(maxLen,windowSize);
                endInd++;//next window
            }
            //case 3
            else if(windowSum>k){
                while(windowSum>k){
                    windowSum-=arr[startInd];//start ko hatate ja
                    startInd++;
                }
                endInd++;
            }
        }
        return maxLen;
    } 
};
int main(){
    Solution s;
    int arr[7]={3,2,1,1,1,4,1};
    cout<<s.lenOfLongSubarr(arr,7,5);
}