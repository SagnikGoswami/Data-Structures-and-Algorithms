#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<long long> printFirstNegativeInteger(long long int arr[],long long int n,long long int k) {
    vector<long long> answer;
    queue<long long> negInd;//to keep track of all the sequence of negative numbers that come into our flow
    //index track as elements maybe repeating but jaise hi ek start index hata check ki woh kahi queue ka front ko noi
    //so agar hai to usko nikal denge
    long long startInd=0,endInd=0;
    while(endInd<n){
        if(arr[endInd]<0) negInd.push(endInd);
        //q ke front mei pehla negative in this window stored rhega as hum continuous start hatate time q ko bhi saaf kr rhe
        long long windowSize=endInd-startInd+1;
        if(windowSize<k){
            //means need to add more elements from back
            endInd++;
        }
        else if(windowSize==k){
            //means this is a valid window so q.front mei get the first negative in this window
            if(negInd.empty()==true) answer.push_back(0);//as noi hai to 0 push kro
            else if(negInd.empty()==false) answer.push_back(arr[negInd.front()]);
            //Now before removing the starting element from queue we also check if that is only in the q's front
            if(negInd.empty()==false and startInd==negInd.front()) negInd.pop();
            startInd++,endInd++;//window moved to keep size same
        }
    }
    return answer;
}