#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//s and t of same size now s[i]->t[i] banane ka cost abs(s[i]-t[i])
//aur maxCost barabar kharcha kr pa tell the longest Substring of s and t
//same bana sak
class Solution {
public:
    int equalSubstring(string s,string t,int maxCost) {
        //state = cost(to make window dono ka same)
        //invalid state = cost>maxCost
        int cost=0,startInd=0,longestSubstr=0;
        int n=s.size();
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt endInd
            char sEndChar=s[endInd];
            char tEndChar=t[endInd];
            cost=cost+abs(sEndChar-tEndChar);
            //Now if it is invalid we remove calculations wrt startInd
            while(cost>maxCost){
                char sStartChar=s[startInd];
                char tStartChar=t[startInd];
                cost=cost-abs(sStartChar-tStartChar);//removed calculation wrt
                //startInd
                startInd++;
            }
            //this is valid window
            longestSubstr=max(longestSubstr,endInd-startInd+1);
        }
        return longestSubstr;
    }
};