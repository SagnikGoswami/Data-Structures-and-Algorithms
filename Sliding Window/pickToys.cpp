//Can pick how many max toys agar baas 2 hi type ke toys le skte aur
//line se toy pick
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Clearly continuous toys ko hi pick kr skte also 2 hi type ke le skte
//so window size kitna bhi ho number of unique toys should be 2
//So variable sliding window

//Clearly window size will be the number of toys picked so yhi maximize krna
int getMaxToys(vector<int> &arr){
    int startInd=0,endInd=0;
    int n=arr.size();
    unordered_map<int,int> toyCount;//this should have a size 2 for 2 unique toys
    int maxToys=0;
    while(endInd<n){
        int endToy=arr[endInd];
        toyCount[endToy]++;
        if(toyCount.size()<2){
            //means 1 hi unique toy mila so aur try to pick
            endInd++;
        }
        else if(toyCount.size()==2){
            //means exactly 2 toys so yeh window valid hai
            int numToys=endInd-startInd+1;
            maxToys=max(maxToys,numToys);//calculation se answer nikala
            endInd++;
        }
        else if(toyCount.size()>2){
            while(toyCount.size()>2){
                //means jyada toy hogya so remove kro start se
                int startToy=arr[startInd];
                toyCount[startToy]--;
                if(toyCount[startToy]==0) toyCount.erase(startToy);
                startInd++;
            }
            if(toyCount.size()==2) maxToys=max(maxToys,endInd-startInd+1);
            endInd++;
        }
    }
    return maxToys;
}
int main(){
    vector<int> toys={1,4,5,3,3,2,1,1,1,2,2};
    cout<<getMaxToys(toys);
}