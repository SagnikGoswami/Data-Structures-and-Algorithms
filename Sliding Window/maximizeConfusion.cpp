//can swap any k to other ie. T to F now tell the max same continuous answer
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //state = window mei count of T and count of F
        //invalid state = min(countTrue,countFalse)>k
        //as then min walle ko change krne ke liye >k operations lag
        int startInd=0,countTrue=0,countFalse=0,longestWindow=0,n=answerKey.size();
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt ending char
            char endChar=answerKey[endInd];
            countTrue=countTrue+(endChar=='T');
            countFalse=countFalse+(endChar=='F');
            //Now if the window is invalid then start ko remove
            //jab tak window invalid

            //but one case is all are true/all false in window then no need to increment start
            int minCount=min(countTrue,countFalse);
            while(minCount>k){
                char startChar=answerKey[startInd];
                countTrue=countTrue-(startChar=='T');
                countFalse=countFalse-(startChar=='F');
                minCount=min(countTrue,countFalse);
                startInd++;
            }
            int windowSize=endInd-startInd+1;
            longestWindow=max(longestWindow,windowSize);
        }
        return longestWindow;
    }
};