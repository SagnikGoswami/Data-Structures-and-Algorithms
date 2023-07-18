#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
private:
    bool isOpening(char ch){
        return (ch=='(' or ch=='{' or ch=='[');
    }
    bool isClosing(char ch){
        return (ch==')' or ch=='}' or ch==']');
    }
    bool isCompliment(char stackTop,char it){
        return ((stackTop=='(' and it==')') or (stackTop=='{' and it=='}') or (stackTop=='[' and it==']'));
    }
public:
    bool isValid(string s){
        stack<char> st;
        for(auto it : s){
            if(isOpening(it)) st.push(it);
            else if(isClosing(it)){
                if(st.empty()) return false;//closing brackets jyada hai
                else if(!isCompliment(st.top(),it)) return false;//as then complimentary pair nahi mila
                else st.pop();
            }
        }
        return st.empty();//ie. agar not empty then false ie. opening brackets jyada the
    }
};