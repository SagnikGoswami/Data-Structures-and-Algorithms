#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &compatibility,vector<int> &efficiency,int k){
    int n=compatibility.size();
    vector<pair<int,int>> compEff;
    for(int i=0;i<n;i++) compEff.push_back({compatibility[i],efficiency[i]});
    sort(compEff.begin(),compEff.end()); 
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int sumEfficiency=0;
    for(int i=1;i<=k-1;i++){
        minHeap.push(compEff[n-i].second);
        sumEfficiency=sumEfficiency+compEff[n-i].second;
    }
    int answer=INT_MIN;
    for(int i=n-k;i>=0;i--){
        int minElem=compEff[i].first;
        sumEfficiency=sumEfficiency+compEff[i].second; 
        minHeap.push(compEff[i].second);
        answer=max(answer,minElem*sumEfficiency);
        sumEfficiency=sumEfficiency-minHeap.top();
        minHeap.pop();
    }
    return answer;
}
int main(){
    vector<int> compatibility={7,9,17,7,8,5,12,4};
    vector<int> efficiency={13,10,7,1,3,12,15,5};
    cout<<solve(compatibility,efficiency,4);
}