//Every Child atleast 1 candy, and child more candies than the lower ratings
//neighbours. Find the minimum number of candies need to give

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Approach 1: O(nlogn) time and O(n) space
typedef pair<int,int> numIndex; //{number,index}
class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<numIndex,vector<numIndex>,greater<numIndex>> minHeap;//so that can access the minimum very fast
        int n=ratings.size();
        for(int i=0;i<n;i++){
            minHeap.push({ratings[i],i});
        }
        //Now we got our minHeap ready, we can get the index of the next minimum elements in O(1)
        vector<int> numCandies(n,1);//ie. numCandies[i] stores how many candies will be given to ith child
        //Sum of this wd give me answer
        //Now for min we need to give just 1 more to higher rating neighbour as more dena so min more dena 
        //means 1 more do
        while(minHeap.empty()==false){ //empty then stop as then saare elements processed
            int nextMinRating=minHeap.top().first;
            int nextMinInd=minHeap.top().second;//we check both direction of index
            minHeap.pop();
            if(nextMinInd>0){
                //means we wd have a children to it's left
                int leftInd=nextMinInd-1;
                int leftChildRating=ratings[leftInd];
                if(nextMinRating<leftChildRating and numCandies[leftInd]<=numCandies[nextMinInd]){
                    //means left child ka rating 1 badha than current
                    numCandies[leftInd]=1+numCandies[nextMinInd];
                }
            }
            if(nextMinInd<n-1){
                //means we wd have a children to it's right
                int rightInd=nextMinInd+1;
                int rightChildRating=ratings[rightInd];
                if(nextMinRating<rightChildRating and numCandies[rightInd]<=numCandies[nextMinInd]){
                    //2nd condition as agar already badha hai then noi badhana
                    //means right child ka rating 1 badha than current
                    numCandies[rightInd]=1+numCandies[nextMinInd];
                }
            }
        }
        int answer=0;
        for(int i=0;i<n;i++){
            answer+=numCandies[i];
        }
        return answer;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        //we calculate the left side se slope and right side se slope by 2 passes one left->right and other
        //right->right and then jis bhi side se ek element ka slope more aata means utna candy atleast
        //dena padega so that dono side se jyada ho
        int n=ratings.size();
        vector<int> leftSlope(n,1);
        vector<int> rightSlope(n,1);
        for(int i=1;i<n;i++){
            int leftInd=i,rightInd=n-1-i;//so that dono side se done ek hi pass mei
            if(ratings[leftInd-1]<ratings[leftInd]) leftSlope[leftInd]=1+leftSlope[leftInd-1];
            //as left slope[i] stores i tak kitne numbers consecutive increasing
            if(ratings[rightInd]>ratings[rightInd+1]) rightSlope[rightInd]=1+rightSlope[rightInd+1];
            //as right slope[i] stores right se i tak r->l kitne consecutive increasing
        }
        int answer=0;
        //Now dono mei se maximum jiss side se bhi jyada numbers badhke aa utne chocholate denge
        //toh dono side se jyada mil agar rating jyada ho
        for(int i=0;i<n;i++){
            answer+=max(leftSlope[i],rightSlope[i]);
        }
        return answer;
    }
};

