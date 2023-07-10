#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Again jinn k numbers ka frequency maximum whi take
// so now priority/key will be the frequency and not number itself
// min heap lenge as then filter out the k size ke bahar walle 

typedef pair<int,int> p;
void getFrequencies(vector<int> &nums,int n,unordered_map<int,int> &freq){
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
}
vector<int> topKFrequent(vector<int>& nums,int k) {
    priority_queue<p,vector<p>,greater<p>> minHeap;
    int n=nums.size();
    // Frequency can store in some map
    unordered_map<int,int> freq;
    getFrequencies(nums,n,freq);

    //map mei traverse as nums mei then duplicate elements push
    for(auto it : freq){
        minHeap.push({it.second,it.first});
        if(minHeap.size()>k) minHeap.pop();
    }
    //clearly min heap mei joh k elements unka freq is maximum

    vector<int> answer;
    while(minHeap.empty()==false){
        answer.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return answer;
}

// Agar bolte sort based on frequency then  minimum freq walla chahiye
// so minHeap mei saare daal aur ek ek krke nikalte jaa, key same