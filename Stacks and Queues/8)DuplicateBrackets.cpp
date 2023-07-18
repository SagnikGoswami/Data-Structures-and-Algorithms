#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
bool duplicateParanthesis(string &expr){
    //Jab ) mil toh tab tak pop till ( not mil agar direct ( mil jaata hai iska matlab
    //kuch content woh walla '(' ')' pair contain hi nahi krta so duplicate
    stack<char> st;
    for(auto it : expr){
        if(it!=')') st.push(it);
        else if(it==')'){
            if(st.top()=='(') return true;//as that would mean directly ( mila no content inside
            while(st.top()!='(') st.pop();
            //then comes ( so usko bhi pop
            st.pop();
        }
    }
    //Agar reach here and no such ) ke wrt ek ( mila directly means no duplicates
    return false;//noi mila
}