#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<int> twoSum(const vector<int> &A, int B){
    unordered_map<int,vector<int>> index; //number,index
    int n=A.size();
    for(int i=0;i<n;i++){
        index[A[i]].push_back(i); //vector mei daal as multiple A[i] ho skte
        //sabko consider kar
    }
    //min index 2 priority
    vector<int> ans; //we will update accordingly(line 21)
    for(int i=0;i<n;i++){
        if(index.count(B-A[i])!=0){
            //pakke se index stored will be min of B-A[i]
            int firstInd=i;
            for(auto secondInd : index[B-A[i]]){
                int index1=min(firstInd,secondInd);
                int index2=max(firstInd,secondInd);
                if(index1==index2) continue;
                if(ans.size()==0 or index2<ans[1] or (ans[1]==index2 and index1<ans[0])){
                    ans={index1,index2};
                }
            }
        }
    }
    if(ans.size()==0) return ans;
    else{
        ans[0]++; //as 1 based indexing bola
        ans[1]++;
        return ans; 
    }
}
int main(){
    vector<int> A={4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    int B=-3;
    cout<<twoSum(A,B)[0]<<" "<<twoSum(A,B)[1];
}