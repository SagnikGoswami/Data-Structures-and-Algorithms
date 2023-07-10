//There are n cards, need to divide them into groupSize consecutive cards walle grp.
//Possible to group/not

// The approach is going to be there will be n/groupSize groups if possible so, we check the min among
// all not taken in any of the groups so that is fixed to come at start of the group as consecutive
// so min want current so heap use min heap, also need to maintain hashmap as 1,2,1,3,4,2,1 then take 1,2,3
// can't pop 2 and 3 out directly so reduce thier count so that they can't come in any grp
// so min popped out if count is 0 then they will not be put in any of the groups
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
private:
    unordered_map<int,int> getFrequency(vector<int>& hand){
        unordered_map<int,int> freq;
        for(auto it : hand) freq[it]++;
        return freq;
    }
public:
    bool isNStraightHand(vector<int>& hand,int groupSize){
        int n=hand.size();
        if(n%groupSize!=0) return false; //clearly not possible to grp
        unordered_map<int,int> freq=getFrequency(hand); // so we get the counts of all the numbers
        priority_queue<int,vector<int>,greater<int>> minHeap(hand.begin(),hand.end());
        //Now, we pick up cards one by one ie. min one with count non 0
        //If the minHeap is empty then we are certain that each card is placed in any 1 of grps
        //So, we return true
        //Now, midway we found that we could not find groupSize consecutive cards then return false
        while(minHeap.empty()==false){
            int currMin=minHeap.top();
            minHeap.pop();
            if(freq[currMin]==0) continue; //as then already in some other group
            //else we take that into a grp so count reduce of that card
            freq[currMin]--;
            //Now, we check if we can get groupSize-1 consecutive cards 
            for(int offset=1;offset<groupSize;offset++){
                //offset will be the offset to currMin to get next element
                int nextEle=currMin+offset;
                if(freq[nextEle]>0) freq[nextEle]--; //ie. nextEle is found to take that into this grp
                else if(freq[nextEle]==0){
                    //means we couldn't find the next element
                    return false;
                }
            }
        }
        //We reached here means we could successfully make n/groupdSize groups with consecutive elements
        return true;
    }
};