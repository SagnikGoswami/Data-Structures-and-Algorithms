#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//Approach will be agar substring mei relevant character(extra freq of char present in t nahi and char not in t noi)
//is equal to t ka size then the substring is valid so now start se char hatana start so that min length get jaise hi
//relevant count < t.size() wapis end se jodte jaa
class Solution {
public:
    string minWindow(string s, string t){
        unordered_map<char,int> tCount,sCount;
        for(auto it : t) tCount[it]++;
        int startInd=0,endInd=0,relevantCnt=0,m=s.size(),n=t.size();
        int overallStart=-1,overallEnd=-1;
        int minSize=INT_MAX;
        while(endInd<m){
            char endChar=s[endInd];
            //check if endChar ko add krna relevance rkh/not
            sCount[endChar]++;//add toh karenge so that saare char in substring ka count pata ho
            //but relevant count add/not noi pata
            if(tCount.count(endChar)!=0 and sCount[endChar]<=tCount[endChar]){
                //ie. t mei present aur add krne ke baad bhi s ke substring mei count t ke char ke count se exceed nhi kiya
                relevantCnt++;
            }
            //Now agar relevantCnt=n ho jata then start to end is a valid answer so pehle store the substring
            //then check if furthur min possible
            while(relevantCnt==n){
                int len=endInd-startInd+1;//as yeh valid substring 
                //so check if abhi tak se substring se smaller/ not
                if(len<minSize){
                    overallStart=startInd;
                    overallEnd=endInd;
                    minSize=len;
                }
                //Now start ko badha ke dekh more chota answer possible/not
                char startChar=s[startInd];
                sCount[startChar]--;
                startInd++;
                if(tCount.count(startChar)!=0 and sCount[startChar]<tCount[startChar]){
                    //ie. delete krne se freq of start kam ho gya so relevantCnt kam
                    relevantCnt--;
                } 
            }
            //Now yeh while khatam se get the smallest ending at endInd
            endInd++; //furthur end check
        }
        if(overallStart==-1) return {};
        return s.substr(overallStart,minSize);
    }
};