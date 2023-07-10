#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Question is replace element by rank, rank is distance
//from the 0th element in sorted array
//if 2 elements same value then same distance of both

//So we make min heap key=element value so top walla min
//so distance=1 but kaunse index ke liye index store
typedef pair<int,int> p;
class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr,int n){
        vector<int> answer(n);
        priority_queue<p,vector<p>,greater<p>> minHeap;
        for(int i=0;i<n;i++) minHeap.push({arr[i],i});
        int rank=1;
        while(minHeap.empty()==false){
            int index=minHeap.top().second;
            int currMin=minHeap.top().first;
            minHeap.pop();
            answer[index]=rank; //as joh element out uska rank next hi
            int nextMin;
            if(minHeap.empty()==false) nextMin=minHeap.top().first;
            //rank increase tabhi kr when next smallest element current se more
            //else distance same
            if(nextMin>currMin) rank++;
        }
        return answer;
    }
};