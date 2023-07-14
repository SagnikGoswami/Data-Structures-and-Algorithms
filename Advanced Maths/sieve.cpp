#include <iostream>
using namespace std;
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
//Complexity to create sieve is O(nlog(logn))