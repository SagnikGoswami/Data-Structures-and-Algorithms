//2 arrays given, now tell the C max sum of pairs where 1 element from arr1 and other from arr2

//1,3,4,2 and 6,4,5,2 clearly max sum walla dono ka max ka sum so 6+4=10
//Now next max O(1) mei nikalna ho to dono ko reverse sort kro
//(i,j) => A ka ith aur B ka jth ka sum so after sorting 
//next max pakka (0,1) or (1,0) so dono ko push heap mei
//(0,1) and (1,0) both generate (1,1) so set bhi keep to avoid duplicacy
//(vis arr 2D banana padhta but set O(n) so MLE) nahi dega

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    //Pehle Decreasing Order mei sort dono ko so that next index from pq se nikal toh next max get
    sort(A.begin(),A.end(),greater<int>()); 
    sort(B.begin(),B.end(),greater<int>()); 
    priority_queue<pair<int,pair<int,int>>> maxHeap; //{sum,A ka index,B ka index} as sum should be the key
    maxHeap.push({A[0]+B[0],{0,0}}); 
    vector<int> answer;
    int n=A.size();
    set<pair<int,int>> st; //as (0,1) and (1,0) both give (1,1) but 2 baar push nahi krenge
    while(answer.size()<C){
        //jaise hi answer ki size >= C then stop as get answer
        int currSum=maxHeap.top().first;
        int indexA=maxHeap.top().second.first;
        int indexB=maxHeap.top().second.second;
        
        maxHeap.pop();
        answer.push_back(currSum);
        //Now potential next greater sum will be A index+1,B index or A index,B index+1 walle
        //push both
        if(indexA<n-1 and st.count({indexA+1,indexB})==0){
            int nextSum=A[indexA+1]+B[indexB];
            maxHeap.push({nextSum,{indexA+1,indexB}});
            st.insert({indexA+1,indexB});
        }
        if(indexB<n-1 and st.count({indexA,indexB+1})==0){
            int nextSum=A[indexA]+B[indexB+1];
            maxHeap.push({nextSum,{indexA,indexB+1}});
            st.insert({indexA,indexB+1});
        }
    }
    return answer;
}