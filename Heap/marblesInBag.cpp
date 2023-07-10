#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//We have to divide elements in weights into k bags aur agar ith element aur
//jth element in bag then i to j saare in bag ie. each bag has a 
//subarray, cost=weight[i]+weight[j] aise har bag ke liye
//jodd denge, find the maxCost-minCost

//Approach is a b c d e f g h so partition a | b c d | e f g h => (a+a)+(b+d)+(e+h) = (a)+(a+b)+(d+e)+(g) ie. first aur last
//to aayega hi aur clearly jis jagah partition kr rhe | uske left walla ek aur right walla ek aayega
//So what we do is saare consective numbers ka sum leke for max score choose max k walle aur for min score choose min k walle
class Solution {
public:
    long long putMarbles(vector<int>& weights,int k) {
        priority_queue<long long> maxHeap; //get k min walle
        priority_queue<long long,vector<long long>,greater<long long>> minHeap; //get k max walle
        int n=weights.size();
        for(int i=0;i<n-1;i++){
            long long sum=weights[i]+weights[i+1];
            maxHeap.push(sum);
            if(maxHeap.size()>k-1) maxHeap.pop();
            minHeap.push(sum);
            if(minHeap.size()>k-1) minHeap.pop();
        }
        long long maxScore=(long long)weights[0]+weights[n-1],minScore=(long long)weights[0]+weights[n-1];
        while(minHeap.empty()==false){
            maxScore=maxScore+minHeap.top();
            minScore=minScore+maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
        }
        return maxScore-minScore;
    }
};