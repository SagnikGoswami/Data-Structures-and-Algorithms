//L and R do arrays given hai range [L[i],R[i]] now need to tell kaunsa number
//maximum ranges mei aata

//as constraints mei de rkha ki 1e6 tak jaa skta L[i] and R[i]
//so we make a frequency array 1e6+1 length ka 
//Now, L[i] ka count 1 se badha representing wha se ek sequence
//start hua and R[i]+1 ka count 1 se ghata representing joh L[i]
//mei sequence start hua tha woh peechle mei end ho gya
//so iske onwards numbers ko count mat kro uss sequence mei

//Now prefix sum se pta chl jaayega ki woh kitne sequence
//ka part hoga as sequence end ke baad -1 laga rkha so koi seq
//ka part noi to count nahi krenge

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int solve(vector<int> &L,vector<int> &R){
    vector<int> freq(1e6+1,0);
    int n=L.size();
    for(int i=0;i<n;i++){
        int lowerRange=L[i];
        int upperRange=R[i];
        freq[lowerRange]++;
        freq[upperRange+1]--;
    }
    int maxFreq=1;
    int ans=L[0];
    //Now prefix sum lenge
    for(int i=1;i<=1e6;i++){
        freq[i]=freq[i]+freq[i-1];
        if(freq[i]>maxFreq){
            ans=i;
            maxFreq=freq[i];
        }
    }
    return ans;
}
int main(){
    vector<int> L={1,4,3,1};
    vector<int> R={5,8,5,4};
    cout<<solve(L,R);
}