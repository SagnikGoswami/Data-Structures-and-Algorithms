//Only 5,10,20 denominations now need 5 rupee for every lemon 
//tell ki saare customer can go in/ not starting mei no ticket

//So we need to save change for customer having 10 and 20 ke coins
//For 10 we need a change of 1->5 ruppee coin
//For 20 we need a change of 1->5 and 1->10/3->5 ruppee coins
//So we store abhi tak kitne 5 rupee aur 10 rupee hai storage mei

//Pehle bigger denominations dene ka try ie. 10 and 5 instead of 3->5s for later use
//So first check for number of 10 and 5 in case of 20 so that the 5s wallo ko use kar paaye 
//woh 10 ke bhi kaam mei aata hai so greedily 10 ko pehle udha dene ka try krenge


#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int numFiveRupee=0,numTenRupee=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) numFiveRupee++;
            else if(bills[i]==10){
                //We need to check if we have a 5 rupee
                if(numFiveRupee==0) return false;
                else{
                    //We give change to the customer
                    numFiveRupee--;
                    numTenRupee++;
                }
            }
            else if(bills[i]==20){
                //check if 1->10 and 1->5 or 3->5 rupee
                if(numFiveRupee>=1 and numTenRupee>=1){
                    numFiveRupee--;
                    numTenRupee--;
                }
                else if(numFiveRupee>=3){
                    numFiveRupee-=3;
                }
                else return false;
            }
        }
        return true;//as every step we were able to give change tabhi
        //possible reach here
    }
};