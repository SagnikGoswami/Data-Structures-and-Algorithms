//Power set method : Identification constraints recursion jaise(n<=15)
//takes more complexity than recursion O(n*2^n)

//2^n-1 in bits language is (1<<n)-1
//So itne numbers as itne subsets generate honge har ek
//ke binary representation ka bit 1 => take that index elem aur 0 => not take

//like agar n=2 =>
//    1 0 <-bit index, arr=[7,4]
// 0: 0 0 => {}
// 1: 0 1 => {7}
// 2: 1 0 => {4}
// 3: 1 1 => {7,4}
//Aise 4 numbers honge 

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> generateSubsets(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> subsets;
    for(int number=0;number<(1<<n)-1;number++){
        //this numbers's binary bits will be used as pick/not pick
        vector<int> subset;
        for(int bit=0;bit<n;bit++){
            //ith iteration mei check ith bit set or not
            if(number&(1<<bit)){
                //means ith bit will be set so pick
                subset.push_back(arr[bit]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

//Application : Given ek arr hai aur degrees of rotation bhi given hai 
//Need to rotate clockwise and anticlockwise any combination but should have
//sum 0 at end find if possible to have sum = 0 at end or not

//So we may use bit=0 means -arr[bit] add to sum else +arr[bit] ie.
//aise all possible + and - combinations could do agar any of the
//combination gives 0 then return true