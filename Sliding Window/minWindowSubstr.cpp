//t walle string ke saare characters ka count >= than present in t ho
//aise substring batao min size ka

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    string minWindow(string s,string t){
        int startInd=0,endInd=0,overallStart;
        int minSize=INT_MAX;
        int n=s.size(),m=t.size();
        unordered_map<char,int> countS,countT;
        for(auto it : t) countT[it]++;
        int validCharCount=0;//neither extra than count as in T nor extra characters
        while(endInd<n){
            //calculation wrt end index
            char endChar=s[endInd];
            countS[endChar]++;
            if(countT.count(endChar)!=0 and countS[endChar]<=countT[endChar]) validCharCount++;
            if(validCharCount<m) endInd++;
            else if(validCharCount==m){
                //means we have a valid substring of s
                int lenSubstr=endInd-startInd+1;
                //Now we try to remove the start char till we have m valid characters as we are trying to minimize
                //the size of substring
                while(validCharCount==m){
                    if(lenSubstr<minSize){
                        minSize=lenSubstr;
                        overallStart=startInd;
                    }
                    char startChar=s[startInd];
                    countS[startChar]--;
                    if(countT.count(startChar)!=0 and countS[startChar]<countT[startChar]) validCharCount--;
                    startInd++;
                    lenSubstr=endInd-startInd+1;
                }
                endInd++;
            }
            //>m kabhi nahi hoga as jaise hi =m ho rha apan while chala ke <=m hi bana de rhe
        }
        if(minSize==INT_MAX) return "";
        return s.substr(overallStart,minSize);
    }
};