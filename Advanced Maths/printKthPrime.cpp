//Clearly from the sieve array we can have all the sieve[i]=true in vector
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool sieve[1000001];//1e6+1 ka sieve define as constraint
void createSieve(){
    //this is the black box joh create the sieve array
    //for query O(1) mei can access array
    int n=1000000;
    for(int i=2;i<=n;i++) sieve[i]=true;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            //as sqrt(n) tak hi ja as n ka last factor maybe sqrt(n)
            for(int j=2*i;j<=n;j+=i){
                //saare multiples of i mei jaake false mark kr ki not prime
                sieve[j]=false;
            }
        } 
    }
}
int kthPrime(int k){
    vector<int> cache;//to store the prime numbers
    int n=1000000;
    createSieve();//created the sieve array
    for(int i=2;i<=n;i++){
        if(sieve[i]==true) cache.push_back(i);
    }
    return cache[k-1];
}