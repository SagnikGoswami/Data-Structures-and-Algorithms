//Ek pat given jiske kitne anagrams in txt walla string yeh count karna hai
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
private:
    unordered_map<char,int> getCount(string &pat){
        unordered_map<char,int> countPat;
        for(auto it : pat) countPat[it]++;
        return countPat;
    }
public:
	int search(string pat, string txt){
	    int answer=0;
	    int countValidChar=0;//we will have a count of how many chars are valid
	    int startInd=0,endInd=0;
	    int validWindowSize=pat.size();//as the substrings should be of same size as pat to be an anagram of pat
	    //so substring size/window size is set as pat ka size
	    int n=txt.size();
	    unordered_map<char,int> countPat=getCount(pat);
	    unordered_map<char,int> countSubstr;//keep track freq of chars in substring 
	    while(endInd<n){
	        //calculations at end index
	        char endChar=txt[endInd];//current substring's ending character
	        countSubstr[endChar]++;
	        if(countPat.count(endChar)!=0 and countSubstr[endChar]<=countPat[endChar]) countValidChar++;
	        //Window size compute and deal with 2 cases
	        int windowSize=endInd-startInd+1;
	        //case 1
	        if(windowSize<validWindowSize) endInd++;
	        //case 2
	        else if(windowSize==validWindowSize){
	            //means the current window is valid
	            //Calculate answer from the calculations done
	            if(countValidChar==validWindowSize) answer++;//as then all the relevant char are present in substring
	            //with the same freq as in pat
	            //Slide the window
	            char startChar=txt[startInd];
	            countSubstr[startChar]--;
	            //check if the count of an important character is reduced
	            if(countPat.count(startChar)!=0 and countSubstr[startChar]<countPat[startChar]) countValidChar--;
	            startInd++,endInd++;
	        }
	    }
	    return answer;
	}
};
//Window size ko fix krke we ensured that there will not be any case 
//like fxor agar fox ke anagrams dhoondh ie. x jaise extra aur true bol
//extra aane ke no chances