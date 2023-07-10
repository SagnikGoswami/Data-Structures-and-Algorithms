//count 0=count 1 aisa longest subarray dhoondh
//So agar 1 ko 1 aur 0 ko -1 then agar prefix sum i aur j ka same
//means i to j walle ka sum is 0 ie. equal number of 0 and 1

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==1) prefix[i]=1;
        }
        int cummSum=0;
        int maxLength=0;
        unordered_map<int,int> sumIndex;
        for(int i=0;i<n;i++){
            cummSum=cummSum+prefix[i];
            if(cummSum==0){
                maxLength=i+1;
                continue;
            }
            if(sumIndex.count(cummSum)!=0){
                //means got a subarray with equal counts of 1 and 0
                int index=sumIndex[cummSum];
                int len=i-index;
                maxLength=max(maxLength,len);
            }
            else if(sumIndex.count(cummSum)==0){
                sumIndex[cummSum]=i;
            }
        }
        return maxLength;
    }
};

//Extension is count of 1 is one more than 0 so find the subarray with 
//sum as 1 ie. search (cummSum-1) aur edge case agar cummSum=1 then i tak count1=1+count0
int solve(vector<int> &nums){
    int n=nums.size();
    vector<int> prefix(n,-1);
    for(int i=0;i<n;i++){
        if(nums[i]==1) prefix[i]=1;
    }
    int cummSum=0;
    int maxLength=0;
    unordered_map<int,int> sumIndex;
    for(int i=0;i<n;i++){
        cummSum=cummSum+prefix[i];
        if(cummSum==1){
            maxLength=i+1;
            continue;
        }
        if(sumIndex.count(cummSum-1)!=0){
            //means got a subarray with equal counts of 1 and 0
            int index=sumIndex[cummSum-1];
            int len=i-index;
            maxLength=max(maxLength,len);
        }
        if(sumIndex.count(cummSum)==0){
            sumIndex[cummSum]=i;
        }
    }
    return maxLength;
}