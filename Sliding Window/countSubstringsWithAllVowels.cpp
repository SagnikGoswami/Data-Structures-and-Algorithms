#include <iostream>
using namespace std;
#include <bits/stdc++.h>
//All vowels hone chahiye aise substrings count
class Solution {
private:
    bool isVowel(char &c){
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
    }
    int atmost(string &word,int k,int n){
        //count how many substrings have atmost k vowels
        int startInd=0,count=0;
        unordered_map<char,int> countVowel;//count of each vowel how many times
        for(int endInd=0;endInd<n;endInd++){
            char endChar=word[endInd];
            if(isVowel(endChar)==false){
                startInd=endInd+1;
                countVowel.clear();
                continue;
            }
            countVowel[endChar]++;//as here aaya toh vowel hi hoga
            int numVowels=countVowel.size();
            while(numVowels>k){
                //means invalid state
                char startChar=word[startInd];
                countVowel[startChar]--;
                //Now agar count 0 hoja still reh ja entry
                if(countVowel[startChar]==0) countVowel.erase(startChar);
                startInd++;
                numVowels=countVowel.size();
            }
            //come here means we have k vowels in the window
            count=count+(endInd-startInd+1);//so itne substrings hongi
        }
        return count;
    }
public:
    int countVowelSubstrings(string word){
        int n=word.size();
        return atmost(word,5,n)-atmost(word,4,n);
    }
};