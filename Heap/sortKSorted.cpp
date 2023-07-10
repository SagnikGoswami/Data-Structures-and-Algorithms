// k sorted means arr[i] sorted hota to i-k se i+k mei kahi lie krta
// =>Sort krna so need to find smallest
// =>Now [6,5,3,2,8,10,9],k=3 hai so 6 either index 0/1/2/3 mei aa skta
// =>so k size ka window bana sabko heap mei insert
// =>clearly 6,5,3,2 ko array mei daal to 0th index correct mil ja

// Heap use as uss k size window se min nikalna heap se fastest
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sortKsorted(vector<int> &nums,int k){
    int n=nums.size();
    //smallest want from heap so min heap take
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<=k;i++){
        if(k==n) continue; //uss case mei k+1 elements hi nahi hai arr mei
        minHeap.push(nums[i]);
    }
    //Now we start from k+1 and go till end
    int ind=0; //iss index ka sahi value at top of pq
    for(int i=k+1;i<n;i++){
        nums[ind]=minHeap.top();
        minHeap.pop();
        ind++; //as next index target agle iteration mei
        minHeap.push(nums[i]);
    }
    //Now joh bhi elements heap mei sabse top extract aur nums mei
    while(minHeap.empty()==false){
        nums[ind++]=minHeap.top();
        minHeap.pop();
    }
}
int main(){
    vector<int> nums={6,5,3,2,8,10,9};
    sortKsorted(nums,3);
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
}