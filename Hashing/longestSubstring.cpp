//Need to count the longest substring without repeating characters

#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Approach can be to save the index of each character
        //occuring in substring. Now let a is index 5 and we got another 
        //a in substring we can now save the previous result in answer
        //and take startindex to 6.
        unordered_map<char,int> charIndex;
        int n=s.size();
        int startInd=0,endInd=0;
        int maxLen=0;
        while(endInd<n){
            //Our substring from start index to end index
            //end index add krne ke baad invalid ho to start update
            //so pehle end index include krne se pehle
            //check ki count 2 ban or not
            if(charIndex.count(s[endInd])!=0){
                //means after adding it we get duplicate endInd walla char
                //So we update the startInd
                //Now only 1 occurence of endInd walla character in substring
                //but for doing that need to remove the occurences from previous start to new start also
                //as they not a part of subtring anymore
                int prevStartInd=startInd;
                startInd=charIndex[s[endInd]]+1; 
                for(int i=prevStartInd;i<startInd;i++){
                    charIndex.erase(s[i]);
                }
            }   
            charIndex[s[endInd]]=endInd;//so this is new index of s[endIndex]
            int len=endInd-startInd+1;//as substring startInd to endInd
            maxLen=max(maxLen,len);
            endInd++;
        }
        return maxLen;
    }
};