//Agar query de rkha toh prime factor nikal skte by spf(smallest prime factor)
//whi black box create where spf[i] stores the smallest prime factor of i

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define N 1000000
int spf[N+1];
void createSPF(){
    for(int i=2;i<=N;i++) spf[i]=i;//pehle mark with itself as prime numbers
    //are smallest prime factor of themselves
    for(int i=2;i<=N;i++){
        if(spf[i]==i){
            //as then woh prime number as peeche wallo se marked noi hua ek se bhi
            for(int j=i*i;j<=N;j+=i){
                if(spf[j]==j) spf[j]=i;//ie. pehli baar number ko mark kr rhe
            }
        }
    }
}
void printPrimeFactor(int t){
    //t is number of test cases/queries
    createSPF();
    for(int i=0;i<t;i++){
        //Backtrack walla logic
        int n;
        cin>>n;
        //neeche walla O(logn) time as itne hi prime factors ho skte n ke
        while(n!=1){
            cout<<spf[n];
            n=n/spf[n];
        }
    }
}