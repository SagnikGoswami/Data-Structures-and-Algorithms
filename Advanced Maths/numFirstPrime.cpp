//How many numbers have min prime factor as n
//Can store the number of numbers with i as starting index in sieve[i]

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define N 1000000

int sieve[N+1];//1e6+1 ka sieve define as constraint default global mei sab 0
void createSieve(){
    for(int i=2;i<=N;i++) sieve[i]=1;
    for(int i=2;i<=N;i++){
        if(sieve[i]==1){
            //means prime hai as abhi tak koi noi mark
            for(int j=2*i;j<=N;j+=i){
                if(sieve[j]==0){
                    //means kisi aur kam prime number nei mark kar diya hoga
                    continue;
                }
                sieve[j]=0;
                sieve[i]++;//so that can count how many have i as first prime
            }
        }
    }
}