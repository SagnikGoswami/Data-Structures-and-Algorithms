#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//Need to increment the first occurence of number except the number standing at
//by 1 give the status of final array
vector<int> solve(vector<int> &A) {
    unordered_map<int,set<int>> index; //set taken so that can get the
    //first occurence at the starting 
    int n=A.size();
    vector<int> answer=A;
    for(int i=0;i<n;i++){
        int elem=A[i];
        if(index.count(elem)!=0 and index[elem].size()>0){
            //get first index at beginning
            int firstOccurence=*(index[elem].begin());
            answer[firstOccurence]++;
            index[elem].erase(firstOccurence);
            index[elem+1].insert(firstOccurence);
        }
        //as ith mei elem mil toh ith ko noi update so add
        index[elem].insert(i);
    }
    return answer;
}