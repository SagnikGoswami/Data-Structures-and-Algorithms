#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        //state=count[any character]
        //invalid=count[endChar]>1
        int startInd=0,longestSubstr=0;
        int n=s.size();
        unordered_map<char,int> count;//for state storing
        for(int endInd=0;endInd<n;endInd++){
            //update state wrt end char
            char endChar=s[endInd];
            count[endChar]++;
            //Now it will be invalid if count of endChar becomes more than 1 as all shd be distinct
            while(count[endChar]>1){
                //baas endChar ka hi count check as baaki char ka count 1 tabhi valid bola hai
                //end char hi naya member of window so whi purane member of window ka count badha skta
                char startChar=s[startInd];
                startInd++;
                count[startChar]--;
            }
            int lenSubstr=endInd-startInd+1;
            longestSubstr=max(longestSubstr,lenSubstr);
        }
        return longestSubstr;
    }
};