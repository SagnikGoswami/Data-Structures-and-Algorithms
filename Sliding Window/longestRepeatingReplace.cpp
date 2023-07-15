#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//can change any char to any other k times now tell the longest substring 
//having same char
class Solution {
private:
    bool isValid(unordered_map<char,int> &count,int &subarrSize,int &k){
        int maxFreq=0;
        for(auto it : count){
            int freq=it.second;
            maxFreq=max(maxFreq,freq);
        }
        //got maximum frequency
        return (subarrSize-maxFreq<=k);
    }
public:
    int characterReplacement(string s,int k) {
        //state=count[char]
        //invalid state=len(substring)-maxOcurring char in substring>k
        unordered_map<char,int> count;
        int startInd=0,longestSubstr=1;
        int n=s.size();
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt end index to check if pehle to valid tha ab aur elements add se valid reh/not
            char endChar=s[endInd];
            count[endChar]++;
            //Now check valid window if not remove the state wrt start
            int subarrSize=endInd-startInd+1;
            while(isValid(count,subarrSize,k)==false){
                char startChar=s[startInd];
                count[startChar]--;
                startInd++;
                subarrSize=endInd-startInd+1;
            }
            //Now start to end will be a valid window
            //may argue ....start.....end so maybe start ke pehle se end ke baad tak koi aur ho so whi longest
            //but ho hi nahi skta as start ko aage tabhi badhaya as <end koi element tak len(substring)-maxOcurring char>k
            //so abhi bhi agar <start and >end ka lele toh invalid hi hoga

            longestSubstr=max(longestSubstr,subarrSize);
        }
        return longestSubstr;
    }
};