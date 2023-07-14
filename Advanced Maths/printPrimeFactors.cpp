//max ek factor sqrt(n) tak jaa skta and need to check the other factor
//agar same to not count else count
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<int> primeFactors(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i); //as 48=>2*2*2*2*3 ie. tab tak divide krte jao
            //till still divisible by i
            //48->24->12->6->3 now 3 not divisible so break
            n=n/i;
        }
    }
    if(n>1) ans.push_back(n);//think of 35
}