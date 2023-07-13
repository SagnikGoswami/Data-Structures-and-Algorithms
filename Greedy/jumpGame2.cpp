//Now min steps nikalne hai
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Method 1: DP se
class Solution {
private:
    int fetchMinJump(int startInd,vector<int>& nums,int n,vector<int> &dp){
        if(startInd>=n-1) return 0;//no need to jump
        if(nums[startInd]==0) return 1e9;//as then can't reach however long jump
        //Now we jump to all possible cases and find out the min
        if(dp[startInd]!=-1) return dp[startInd];
        int minJumps=1e9;
        for(int jump=1;jump<=nums[startInd];jump++){
            //ie. all possible jumps from start
            int tempAns=fetchMinJump(startInd+jump,nums,n,dp);
            //Now if temp is 1e9 that means if we
            //jump to start+jump, we can't reach end
            if(tempAns!=1e9){
                minJumps=min(minJumps,1+tempAns);//as first step we take
            }
        }
        return dp[startInd]=minJumps;
    }
public:
    int jump(vector<int>& nums){
        int startInd=0;
        int n=nums.size();
        vector<int> dp(n,-1);
        return fetchMinJump(startInd,nums,n,dp);
    }
};
//Method 2: BFS krenge ie. ek element ke woh saare adjacent honge
//jaha tak can reach from that element

class State{
public:
    int index;
    int jumpsTillNow;
    State(int index,int jumpsTillNow){
        this->index=index;
        this->jumpsTillNow=jumpsTillNow;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<bool> vis(n,false);
        int jumpsMade=0;
        queue<State> q;
        q.push({0,0});//as 0 jumps made when stand at starting
        vis[0]=true;
        while(q.empty()==false){
            int currInd=q.front().index;
            int currJumps=q.front().jumpsTillNow;
            q.pop();
            //Now visit the adjacent vertex
            for(int jump=1;jump<=nums[currInd];jump++){
                int newInd=currInd+jump;
                if(newInd>=n-1){
                    //means iss level of BFS mei reached end hence yhi min
                    return currJumps+1;
                }
                if(vis[newInd]==true) continue;//pehle se visit kr rkha
                //means ki pehle se ie. kam jumps mei reached so yeh case
                //not considered

                //agar <n-1 ie. not reach end just queue mei push
                q.push({newInd,currJumps+1});
                vis[newInd]=true;
            }
        }
        return -1;//agar not possible to reach
    }
};
//yeh bhi O(n^2) hi hoga

//BFS in a shorter version : We can keep a track of ending of our queue very easily via a pointer in the array
//and from start of queue to the end of the queue is the current level all elements, then when we reach the
//end of the current level then we increment our level and set our new end to the farthest possible index
//reachable from previous level(which we find on the go)
class Solution {
public:
    int jump(vector<int>& nums){
        int currLevelEnd=0,farthestNextLevel=0,level=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            //current level ends at currLevelEnd
            farthestNextLevel=max(farthestNextLevel,i+nums[i]);//as i+nums[i] is the max one can reach from i
            if(i==currLevelEnd){
                //means reached the end of current level next level start will be 
                //from currLevelEnd+1 ie. next i and ends at the farthestNextLevel
                //going on to the next level we increment our level as well
                level++;
                currLevelEnd=farthestNextLevel;
            }
        }
        //As it is guarenteed that we will reach the end so we return the level without any checks
        return level;
    }
};