#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// k ropes ko connect such that cost is minimum
// can go greedy ie. 2 min length ropes ko take join kro then
// result joh usko push wapis 2 ropes uthao

// So as min nikalna sabmei se ko min heap as min fastest nikalke dega
long long minCost(long long arr[],long long n){
    priority_queue<long long,vector<long long>,greater<long long>> minHeap(arr,arr+n);
    //so now all elements inserted in priority queue

    long long cost=0;
    while(minHeap.size()>1){
        //as 1 se jyada ropes needed so that merge kar paaye
        long long minRope=minHeap.top();
        minHeap.pop();
        long long secondMinRope=minHeap.top();
        minHeap.pop();
        long long mergedRope=minRope+secondMinRope;
        cost=cost+mergedRope;
        minHeap.push(mergedRope);
    }
    return cost;
}