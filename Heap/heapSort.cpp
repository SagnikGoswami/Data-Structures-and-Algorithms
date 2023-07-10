#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//below is the code for insert function as well only the endInd=n
void upHeapify(vector<int> &arr,int endInd){
    //last mei insert toh kar diya as Complete Binary Tree satisfy
    //now, we take the endInd to correct place
    int childInd=endInd;
    while(childInd>0){
        int parentInd=(childInd-1)/2;
        if(arr[parentInd]>arr[childInd]){
            //as min heap mei parent chota than child
            swap(arr[childInd],arr[parentInd]);
        }
        else break; //as then sahi jagah pahuch gya endInd
        childInd=parentInd;
    }
}
//below is the code for removeMin also
void downHeapify(vector<int> &arr,int &size){
    swap(arr[0],arr[size-1]);
    size--;
    //iss se as top ko hatana so we replace with last
    //as last ko hata tab bhi CBT reh
    //Now top ko sahi jagah pahucha
    int parentInd=0,leftChildInd=2*parentInd+1,rightChildInd=2*parentInd+2;
    while(leftChildInd<size){
        int minInd=parentInd;
        if(arr[minInd]>arr[leftChildInd]) minInd=leftChildInd;
        //if give and not else if as agar rightchild still smaller 
        //update ho ja
        if(rightChildInd<size and arr[minInd]>arr[rightChildInd]) minInd=rightChildInd;
        if(minInd==parentInd) break;
        swap(arr[minInd],arr[parentInd]);
        parentInd=minInd;
        leftChildInd=2*parentInd+1,rightChildInd=2*parentInd+2;
    }
}
void heapSort(vector<int> &arr){
    int n=arr.size();
    for(int endInd=1;endInd<n;endInd++){
        //0 to endInd yeh maanle ki heap ban chuka ie. endInd ko 
        //inserted to heap now CBT to bann heap order satisfy
        //krane k liye upheapify call
        upHeapify(arr,endInd);
    }
    int size=n;
    while(size>1){
        //yeh assume ki top ko arr se nikal de
        //so last mei store so aise min nikalte jaa rha
        //aur last mei store hota ja rha
        //so decreasing order give
        downHeapify(arr,size);
    }
}