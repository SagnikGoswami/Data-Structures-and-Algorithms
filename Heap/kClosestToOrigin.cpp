#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//clearly here closest so distance will be the key
//We will take max heap ko that filter out max walle

typedef pair<int,pair<int,int>> ppi; // {distance from origin of (x,y),{x,y}}
int getDistance(int xCoord,int yCoord){
    return xCoord*xCoord+yCoord*yCoord;
}
vector<vector<int>> kClosest(vector<vector<int>>& points,int k) {
    priority_queue<ppi> maxHeap;
    int n=points.size();
    for(int i=0;i<n;i++){
        int xCoord=points[i][0];
        int yCoord=points[i][1];
        int distanceFromOrigin=getDistance(xCoord,yCoord);
        maxHeap.push({distanceFromOrigin,{xCoord,yCoord}});
        if(maxHeap.size()>k) maxHeap.pop();
    }
    //Now maxHeap mei jitne bhi k elements honge whi k closest points
    vector<vector<int>> answer;
    while(maxHeap.empty()==false){
        int xCoord=maxHeap.top().second.first;
        int yCoord=maxHeap.top().second.second;
        maxHeap.pop();
        answer.push_back({xCoord,yCoord});
    }
    return answer;
}