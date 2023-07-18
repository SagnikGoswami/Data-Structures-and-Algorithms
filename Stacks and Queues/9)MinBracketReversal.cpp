#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
int countBracketReversals(string input){
	int n=input.size();
	if(n&1) return -1;//as odd then
	stack<char> st;
	for(auto it : input){
		if(it=='{') st.push(it);
		else if(it=='}'){
			if(st.empty() or st.top()=='}') st.push(it);
			else st.pop();
		}
	}
	int cnt=0;
	while(!st.empty()){
		char ch1=st.top();
		st.pop();
		char ch2=st.top();
		st.pop();
		if(ch1==ch2) cnt++;
		else cnt+=2;
	}
	return cnt;
}