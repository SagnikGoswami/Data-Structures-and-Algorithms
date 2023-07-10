#include <iostream>
using namespace std;
#include <bits/stdc++.h>
string fractionToDecimal(int numerator, int denominator) {
    if(numerator==0){
        return "0"; //clearly an edge case
    }
    string ans;
    if((numerator>0)^(denominator>0)){
        ans+='-';//one negative and one postive then - aayega so xor ensures that
    }
    long n=labs(numerator),d=labs(denominator),r=n%d; //labs liya as abs(INT_MIN)=INT_MIN
    ans+=to_string(n/d);
    if(r==0){
        //so remainder is 0 hence ans got
        return ans;
    }
    //Now reach here means need to add decima;
    ans+='.';
    unordered_map<long,int> rs;//stores remainder along with the index where
    //the repeating remainder was first found as we know wapis waha se repeat start
    //so ussi index pe ( lagayenge
    while(r!=0){
        if(rs.count(r)!=0){
            //Means ab repeat krna start krega
            ans.insert(rs[r],"(");
            ans+=')';
            break;
        }
        rs[r]=ans.size();
        //Now can add a 0 at the end of remainder and this we will divide by
        //the dividend to get new remainder
        r*=10;
        ans+=to_string(r/d);
        r%=d;
    }
    return ans;
}