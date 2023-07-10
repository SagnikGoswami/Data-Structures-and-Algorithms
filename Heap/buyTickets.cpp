#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//arr of n people stores unka priority agar line mei khara walle
//se more priority walla koi hai to woh front walle ko ticket nahi mil 
//last mei jodd denge nahi to ticket denge aur ticket dene mei 1 sec 
//lgta time jabtak k ko ticket mil

void setLine(int *arr,int n,queue<int> &line){
    for(int i=0;i<n;i++) line.push(i);
}
int buyTicket(int *arr, int n, int k){
    priority_queue<int> maxHeap(arr,arr+n); //this will store the priorities aur max walla get krne mei easy hoga
    queue<int> line; //each person is represented by index
    setLine(arr,n,line); //initially get all people standing in line ismei
    int time=0;
    while(line.empty()==false){
        int frontGuy=line.front(); //joh currently line ke aage lag
        line.pop();
        int maxPriority=maxHeap.top(); //so top se get max priority
        if(maxPriority==arr[frontGuy]){
            //matlab front guy ko ticket mil so get
            time++;
            maxHeap.pop();
            if(frontGuy==k) return time;
        }
        else{
            //front guy last pe jaake wait krega
            line.push(frontGuy);
        }
    }
}