//Agar child ko cookie dena then uss cookie ka size>uska greed aise max
//kitne children ko cookie de skte
//So selection criteria of any cookie is greed se uska size badha ho
//aur jyada se jyada chota ho taaki more greedier ke liye badhe cookies
//bacha ke rkh ske

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Basically less greedy child ko smaller cookie deke khush kr denge taaki joh more greedy childern
//unke liye badhe size ka cookie bache

//Agar ek size ke cookie se greed noi meet then next bigger cookie try
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int numChildren=g.size(),numCookies=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //Now we can have 2 pointer, 1 each on each of the 2 arrays
        int maxChildren=0;//max children who get cookie
        int childInd=0,cookieInd=0;
        while(childInd<numChildren and cookieInd<numCookies){
            int childGreed=g[childInd],cookieSize=s[cookieInd];
            if(childGreed<=cookieSize){
                maxChildren++;
                childInd++,cookieInd++;
            }
            else if(cookieSize<childGreed){
                cookieInd++;
            }
        }
        return maxChildren;
    }
};