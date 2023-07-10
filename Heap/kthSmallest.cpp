// k+smallest so heap ka sawal identified
// smallest bola so max Heap lenge
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kSmallest(vector<int> &arr,int k){
    int n=arr.size();
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(arr[i]);
        //Now push krne ke baad agar size of heap k se bada
        //means joh top walla element woh atleast k numbers se
        //to bada so kth smallest element nahi ho skta
        //so remove that
        if(maxHeap.size()>k) maxHeap.pop();
    }
    return maxHeap.top();
}

//Follow up maybe ki k1th smallest aur k2th smallest ke beech ke numbers
//ka sum nikalo

//So in that case, we find bari bari se k1 and k2 smallest
//Then we traverse the array and add to sum agar dono ke beech lie num[i]