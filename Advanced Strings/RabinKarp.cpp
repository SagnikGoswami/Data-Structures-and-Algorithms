#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MOD 101//any prime number could take so took a big prime 101

class Solution{
private:
    long long power(int x,int n){
        long long res=1;
        for(int i=0;i<n;i++){
            res=(res*x)%MOD;
        }
        return res;
    }
    vector<int> search(string &text,string &pattern){
        int d=256;//number of characters yhi hai base like decimal base 10
        //here hash ka base is 256
        vector<int> ans;
        int textSize=text.size(),patternSize=pattern.size();
        int textHash=0,patternHash=0;
        int mostSignificantPower=power(d,patternSize-1);
        //calculation of hash of first window in text and that of pattern
        for(int i=0;i<patternSize;i++){
            textHash=(textHash*d+text[i])%MOD;
            patternHash=(patternHash*d+pattern[i])%MOD;
        }
        //Now we check each substring of windowsize ki hash same as
        //patternHash or not
        for(int startInd=0;startInd<=(textSize-patternSize);startInd++){
            //textHash stores hash of text.substr(startInd,patternSize)
            if(textHash==patternHash){
                //will check all the characters
                if(text.substr(startInd,patternSize)==pattern) ans.push_back(startInd);//found an index
            }
            //Now for next window updating the hash of text
            textHash=((textHash-(text[startInd]*mostSignificantPower))*d+(text[startInd+patternSize]))%MOD;//as start+pattern size walla char hi add new  window mei
            if(textHash<0) textHash+=MOD;
        }
        return ans;
    }
public:
    vector<int> findIndex(string &text,string &pattern){
        return search(text,pattern);
    }
};
int main(){
    Solution s;
    string text,pattern;
    cin>>text>>pattern;
    vector<int> ans=s.findIndex(text,pattern);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}