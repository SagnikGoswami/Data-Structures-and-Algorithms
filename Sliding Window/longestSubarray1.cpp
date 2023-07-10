// Longest subarray with all 1 need to print and you should delete 1 element
// So atmax 1 -> 0 is allowed in the subarray

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int longestSubarray(vector<int>& nums){
        //startInd represents start of the subarray
        int startInd=0,maxLen=0,count0=0;
        int zeroInd=-1;
        int n=nums.size();
        for(int endInd=0;endInd<n;endInd++){
            //subarray from startInd to endInd
            if(nums[endInd]==0 and count0==0){
                //means 1st zero encountered allowed hai 1 zero tak
                count0++;
                zeroInd=endInd;
                int lenSubarray=endInd-startInd; //actually end-start+1 hota but as ek 0 delete
                maxLen=max(maxLen,lenSubarray); //as this valid subarray so update
            }
            else if(nums[endInd]==0 and count0==1){
                //means subarray ka 2nd 0 at endInd so not allowed
                startInd=zeroInd+1; // as 1 1 0 1 1 1 0 so endInd=6 so startInd=3 so that 1 hi 0
                zeroInd=endInd;
                //count0 1 hi reh as woh purana zero out new zero entered
                int lenSubarray=endInd-startInd;
                maxLen=max(maxLen,lenSubarray);
            }
            else if(nums[endInd]!=0 and count0<=1){
                int lenSubarray=endInd-startInd; //as should delete so end-start agar no 0 bhi ho
                //in the subarray or 1 zero ho
                maxLen=max(maxLen,lenSubarray);
            }
        }
        return maxLen;
    }
};

//approach 2

//We can keep a track of how many 1 we encountered before hitting a zero in prev Count
//Now, we can again keep a count of how many 1 we encounter till we reach the next 0
//So now count+prevCount would give us the subarray which included that prev 0 
//We can update the result for all 0 present
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),prevCount=0,count=0,maxLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
            else if(nums[i]==0){
                //encountered a new 0 so, we count what was the length of subarray
                //which had the prev 0 in the subarray
                maxLen=max(maxLen,count+prevCount);
                prevCount=count; //So now the current 0 becomes the previous 0
                count=0;
            }
        }
        //Now, we did not consider the case when the previous 0 doesn't get any 0 
        //after him so the count of 1 after that previous 0 will be stored in count
        //we update our answer

        maxLen=max(maxLen,count+prevCount);
        //Now if all are 1 then count==len(nums) so answer is n-1
        if(count==n) return n-1;
        else return maxLen;
    }
};

//approach 3

// DP approach will be dp[i][0] stores the length of longest subarray with numzeros=0
// ending at index i and dp[i][1] stores the length of longest subarray with numzeros=1
// and ending at i

// So if(nums[i]=0) then dp[i][0]=0 and dp[i][1]=dp[i-1][1] as we need to delete the previous 0 then and in the first case
// for till i to be 1 we need to have nums[i]=1 
// and if(nums[i]=1) then dp[i][0]=1+dp[i-1][0] as one more 1 is added and dp[i][1]=1+dp[i-1][0] as i-1 tak saare 1 walla subarray need so that at end yeh 0 add
// base case independent case ie. dp[0][0]=0 if nums[0]=0 and 1 if nums[1]=1 so dp[0][0]=nums[0]
// dp[0][1]=0 for any case as if nums[i]=0 then length of subarray will be 0 as no 1 and if 1 then as there are no 0 so 
// the length of subarray is 0

class Solution {
private:
    int spaceOptimize(vector<int> &nums){
        int n=nums.size();
        int prev0=nums[0];
        int prev1=0;
        int count1=0;
        if(nums[0]==1) count1=1;
        int maxLen=0;
        for(int i=1;i<n;i++){
            int curr0,curr1;
            if(nums[i]==0){
                curr0=0;
                curr1=prev0;
            }
            else if(nums[i]==1){
                count1++;
                curr0=prev0+1;
                curr1=prev1+1;
            }
            maxLen=max(maxLen,max(curr0,curr1));
            prev0=curr0;
            prev1=curr1;
        }
        if(count1==n) return n-1;
        else return maxLen;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        int maxLen=0;
        int count1=0; //for handling edge case of all 1
        if(nums[0]==1){
            dp[0][0]=1;
            count1++;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                dp[i][0]=0;
                dp[i][1]=dp[i-1][0];
            }
            else if(nums[i]==1){
                count1++;
                dp[i][0]=1+dp[i-1][0];
                dp[i][1]=1+dp[i-1][1];
            }
            maxLen=max(maxLen,max(dp[i][0],dp[i][1]));
        }
        if(count1==n) return n-1;
        return maxLen;
    }
};

// Now agar bolta ki k should delete so k tak 0 rkh skte
// so dp[i][j] => j number of 0 walla max length subarray ending at i
// if(nums[i]=0) now dp[i][0]=0 and rest j=1 to k dp[i][j]=dp[i-1][j-1] 
// this is becoz j-1 tak 0's are allowed till i-1 as with j zeros hai 
// dp[i][j] and if(nums[i]=1) dp[i][j]=1+dp[i-1][j] this is becoz
// any case mei 1 judd at the end
// independent case mei agar nums[0]=1 then dp[0][0]=1
// baaki sab 0

class Solution{
private:
    int spaceOptimize(vector<int> &nums,int k){
        vector<int> prev(k+1,0);
        int maxLen=0;
        int count1=0;
        int n=nums.size();
        if(nums[0]==1){
            prev[0]=1;
            count1++;
        }
        for(int i=1;i<n;i++){
            vector<int> curr(k+1,0);
            if(nums[i]==0){
                curr[0]=0;
                for(int j=1;j<=k;j++){
                    curr[j]=prev[j-1];
                    maxLen=max(maxLen,curr[j]);
                }
            }
            else if(nums[i]==1){
                count1++;
                for(int j=0;j<=k;j++){
                    curr[j]=1+prev[j];
                    maxLen=max(maxLen,curr[j]);
                }
            }
            prev=curr;
        }
        if(count1==n) return n-k;
        return maxLen;
    }
public:
    int longestSubarray(vector<int> &nums,int k){
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        int maxLen=0;
        int count1=0;
        if(nums[0]==1){ 
            dp[0][0]=1;
            count1=1;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                dp[i][0]=0;
                for(int j=1;j<=k;j++){
                    dp[i][j]=dp[i-1][j-1];
                    maxLen=max(maxLen,dp[i][j]);
                }
            }
            else if(nums[i]==1){
                count1++;
                for(int j=0;j<=k;j++){
                    dp[i][j]=1+dp[i-1][j];
                    maxLen=max(maxLen,dp[i][j]);
                }
            }
        }
        if(count1==n) return n-k;
        return maxLen;
    }
};