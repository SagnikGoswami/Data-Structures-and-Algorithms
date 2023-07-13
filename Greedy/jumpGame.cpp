//We can get the max we can reach if we stand at current index by just
//adding the index to the nums[index] now if any of them give
//answer as >=n-1 then answer is true
//But we also need to check if that index is reachable from start
//Max till now represents ki start se kaha tak pahuch skte 
//agar i aisa ki max se bhi badha => start se hi uska nahi pahuch skte so false
//direct return

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxReachable=0;
        for(int i=0;i<n;i++){
            if(i>maxReachable) return false;
            maxReachable=max(maxReachable,nums[i]+i);//har index mei
            //isko update krenge so that pata rhe ki har index
            //se kaha tak pahuch skte
            if(maxReachable>=n-1) return true;//as then
            //i se reach end aur if(i>maxReachable) se made sure that
            //i tak bhi pahuch skte
        }
        return false;
    }
};