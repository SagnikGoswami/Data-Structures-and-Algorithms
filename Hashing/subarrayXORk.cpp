#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(vector<int> &A, int B){
    unordered_map<int,int> xorCount; //count how many ending point tak xor x
    //as if [1,2,3]^(B)=x then [1,2,3]=x^B so search for
    //how many previous have x^B as cummulative xor
    int cummulativeXOR=0;
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++){
        cummulativeXOR=cummulativeXOR^A[i];
        if(cummulativeXOR==B) count+=1;
        if(xorCount.count(cummulativeXOR^B)!=0){
            count+=xorCount[cummulativeXOR^B];
        }
        xorCount[cummulativeXOR]++;
    }
    return count;
}
