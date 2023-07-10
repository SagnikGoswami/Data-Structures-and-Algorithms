//Find all the starting index wrt which substring has all words in B exactly once
//(starting index of all substring batana)
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool valid(int startInd,int m,int n,int size,string &A,unordered_map<string,int> &freq){
    unordered_map<string,int> seen;
    int it=startInd;
    while(it<size and it<startInd+m*n){
        string searchSubstr=A.substr(it,m);//length m word joh startInd se start hota
        if(freq.count(searchSubstr)!=0 and seen[searchSubstr]<freq[searchSubstr]){
            //means word pehle noi aaya aur present hai word list mei
            seen[searchSubstr]++;
            it=it+m;//next word search
        }
        else return false;
    }
    //reached here now agar vis.size() not n implies hone se pehle word khtm ie. startInd=size so return false else true
    return (it==startInd+m*n); //in a single line :)
}
vector<int> findSubstring(string A, const vector<string> &B) {
    int size=A.size();
    int n=B.size();
    int m=B[0].size();
    unordered_map<string,int> freq;
    vector<int> ans;
    for(int startInd=0;startInd<size;startInd++){
        if(valid(startInd,m,n,size,A,freq)==true){
            ans.push_back(startInd);
        }
    }
    return ans;
}