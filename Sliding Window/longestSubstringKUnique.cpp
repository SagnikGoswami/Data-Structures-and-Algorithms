#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
  public:
    int longestKSubstr(string s,int k) {
        int startInd=0,endInd=0;
        unordered_map<char,int> charCount;
        int n=s.size();
        int longestLen=-1;
        while(endInd<n){
            //calculation wrt endInd
            char endChar=s[endInd];
            charCount[endChar]++;
            int numUniqueChar=charCount.size();//as issi pe condition made
            if(numUniqueChar<k) endInd++;
            else if(numUniqueChar==k){
                //answer update as the current substring potential candidate
                int currLen=endInd-startInd+1;
                longestLen=max(longestLen,currLen);
                //end ko aage badha
                endInd++;
            }
            else if(numUniqueChar>k){
                while(numUniqueChar>k){
                    char startChar=s[startInd];
                    charCount[startChar]--;
                    if(charCount[startChar]==0){
                        charCount.erase(startChar);
                    }
                    startInd++;
                    numUniqueChar=charCount.size();
                }
                endInd++;
            } 
        }
        return longestLen;
    }
};