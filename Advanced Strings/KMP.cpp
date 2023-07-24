#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void constructLPS(string &pattern,int LPS[],int n){
    int len=0,i=1;
    LPS[0]=0;
    while(i<n){
        if(pattern[i]==pattern[len]){
            len++;
            LPS[i]=len;
            i++;
        }
        else if(pattern[i]!=pattern[len] and len==0){
            LPS[i]=0;
            i++;
        }
        else if(pattern[i]!=pattern[len] and len>0){
            len=LPS[len-1];
        }
    }
}
vector<int> KMP(string &text,string &pattern){
    int m=text.size(),n=pattern.size();
    vector<int> ans;
    int LPS[n];
    constructLPS(pattern,LPS,n);
    int i=0,j=0;
    while(i<m){
        if(text[i]==pattern[j]) i++,j++;
        if(j==n){
            ans.push_back(i-j);
            j=LPS[j-1];
        }
        else if(i<m and text[i]!=pattern[j]){
            if(j==0) i++;
            else j=LPS[j-1];
        }
    }
    return ans;
}
int main(){
    string text,pattern;
    cin>>text>>pattern;
    vector<int> ans=KMP(text,pattern);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}