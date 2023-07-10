#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<int> &A, int B){
    //even then 0 and odd then 1 now problem reduced to
    //count subarrays with sum B as B odd extra than even tabhi sum
    //of woh subarray will be B
    int n=A.size();
    vector<int> prefix(n);
    for(int i=0;i<n;i++){
        if(A[i]%2==0) prefix[i]=0;//0 kr rhe as number of even se phark noi
        else prefix[i]=1;
    }
    int count=0;
    unordered_map<int,int> sumCount; //keep a count how many prefix
    //have a sum x
    int prefixSum=0;
    for(int i=0;i<n;i++){
        prefixSum=prefixSum+prefix[i];
        if(prefixSum==B){
            count++;
        }
        if(sumCount.count(prefixSum-B)!=0){
            count+=sumCount[prefixSum-B];
        }
        sumCount[prefixSum]++;
    }
    return count;
}
