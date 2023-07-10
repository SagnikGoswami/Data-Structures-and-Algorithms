// Ek number given hoga x array mei x ke k closest numbers nikalo
// so absolute difference jinka x se minimum ho woh k numbers
// so minimum jaldi nikal liya but now key not number itself
// key is absolute differnce with x

// Now max heap banane se max walla upar aake filter out
// so last mei joh k numbes bach whi answer


#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> findClosestElements(vector<int>& arr,int k,int x) {
    priority_queue<pair<int,int>> maxHeap;
    int n=arr.size();
    for(int i=0;i<n;i++){
        maxHeap.push({abs(arr[i]-x),arr[i]});
        if(maxHeap.size()>k) maxHeap.pop();
    }
    vector<int> answer;
    //Now sorted order mei answer want
    //sort se klogk time so shi hai
    while(maxHeap.empty()==false){
        answer.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    sort(answer.begin(),answer.end());
    return answer;
}