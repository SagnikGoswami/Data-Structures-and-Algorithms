#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    int mapping(char ch){
        if(ch=='0') return -1;
        else return 1;
    }
    vector<int> getPrefixArray(string &s,int n){
        vector<int> prefixArray(n+1 , 0 ); 
        for(int i=0;i<n;i++) prefixArray[i+1]=prefixArray[i]+mapping(s[i]);
        return prefixArray;
    }
    int mergeSortedArray(vector<int> &arr,int startInd,int endInd){
        int midInd=startInd+(endInd-startInd)/2;
        int i=0,j=midInd+1,count=0;
        vector<int> mergedArray;
        while(i<=midInd and j<=endInd){
            if(arr[i]<=arr[j]) mergedArray.push_back(arr[i++]);
            else{
                mergedArray.push_back(arr[j++]);
                count=count+(midInd-i+1);
            }
        }
        while(i<=midInd) mergedArray.push_back(arr[i++]);
        while(j<=endInd) mergedArray.push_back(arr[j++]);
        return count;
    }
    int mergeSort(vector<int> &arr,int startInd,int endInd){
        if(startInd>=endInd) return 0;
        int midInd=startInd+(endInd-startInd)/2;
        int leftSubAnswer=mergeSort(arr,startInd,midInd);
        int rightSubAnswer=mergeSort(arr,midInd+1,endInd);
        int mergedAnswer=mergeSortedArray(arr,startInd,endInd);
        return leftSubAnswer+rightSubAnswer+mergedAnswer;
    }
    int countInversion(vector<int> &arr,int n){
        return mergeSort(arr,0,n-1);
    }
    int countSubsetsSumK(vector<int>& nums,int k) {
        int n=nums.size();
        unordered_map<int,int> cummSumFreq;
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==k){
                count++;
            }
            count=count+cummSumFreq[sum-k];
            cummSumFreq[sum]++;
        }
        return count;
    }
public:
    int countSubarray(string &s){
        int n=s.size();
        vector<int> prefixArray=getPrefixArray(s,n); 
        reverse(prefixArray.begin(),prefixArray.end());
        int countSubsetsLess0=countInversion(prefixArray,n+1);
        return countSubsetsLess0;
    }
};
int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.countSubarray(str);
}