#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// chote n/2 elements ko maxHeap mei daal aur badho ko minHeap mei
// this is becoz chote n/2 mei se max hi median contributor in sorted array
// aur badhe n/2 mei se hi min bhi so dono max aur min fastest tareeke se nikalne ka best
// method is heap
class MedianFinder{
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder(){
        // do nothing woh apne aap data members ko initialize kr dega
    }
    
    void addNum(int num){
        if(maxHeap.size()==minHeap.size()){
            //means ek element go to top of max Heap aur whi answer
            //min heap ke top aur num ko compare joh bhi badha woh go to min heap
            if(minHeap.size()==0){
                //then no top in maxheap so num hi insert
                maxHeap.push(num);
            }
            else{
                int minTop=minHeap.top();
                if(minTop<num){
                    //So num is larger woh jaayega min heap mei
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(minTop);
                }
                else{
                    maxHeap.push(num);
                }
            }
        }
        else if(maxHeap.size()>minHeap.size()){
            //Then dono ka size barabar karna hai so max heap ke top aur num mei
            //se joh bhi badha woh go to min heap
            int maxTop=maxHeap.top();
            if(num<maxTop){
                //so maxHeap ka top badha
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(num);
            }
            else{
                //num badha so woh ja min heap mei
                minHeap.push(num);
            }
        }
    }
    
    double findMedian(){
        if(maxHeap.size()==minHeap.size()){
            double maxTop=maxHeap.top();
            int minTop=minHeap.top();
            return (maxTop+minTop)/2;
        }
        else{
            return (double)maxHeap.top();
        }
    }
};