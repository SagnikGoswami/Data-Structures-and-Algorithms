//Need to find the numbers which are present in atleast 2 out of the 3 arrays
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C){
    //1e5 size ka ek array maintain jaha count++ krenge jaise hi 
    //A ya B ya C mei koi element mil
    //Also ensure ek array se ek hi baar aaye so set keep
    //agar count>=2 then ans mei add
    vector<int> count(1e5+1,0);
    unordered_set<int> isPresentA;
    for(auto it : A){
        if(isPresentA.count(it)==0){
            count[it]++;
            isPresentA.insert(it);
        }
    }
    unordered_set<int> isPresentB;
    for(auto it : B){
        if(isPresentB.count(it)==0){
            count[it]++;
            isPresentB.insert(it);
        }
    }
    unordered_set<int> isPresentC;
    for(auto it : C){
        if(isPresentC.count(it)==0){
            count[it]++;
            isPresentC.insert(it);
        }
    }
    vector<int> answer;
    for(int i=1;i<=1e5;i++){
        if(count[i]>=2) answer.push_back(i);
    }
    return answer;
}