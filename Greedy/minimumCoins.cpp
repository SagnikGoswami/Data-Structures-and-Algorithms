#include <bits/stdc++.h> 
//selection procedure will be to take the coin
//with the max denominator smaller than or equal to the 
//remaining amount so that minimum coins use ho
int findMinimumCoins(int amount) 
{
    int coinsUsed=0;
    int denominations[9]={1,2,5,10,20,50,100,500,1000};
    int i=8;
    while(i>=0 and amount>0){
        //as 9 denominations
        if(denominations[i]<=amount){
            coinsUsed+=1;
            amount-=denominations[i];
        }
        else if(amount<denominations[i]) i--;
    }
    return coinsUsed;
}
//Greedy will fail if sum of 2 denominations exceed another