#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Approach 1: Using O(n) pop and O(1) push
class MyQueue {
private:
    //at a particular instance all elements of queue either s1 mei honge
    //or s2 mei honge saare
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue(){}
    
    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        if(empty()) return -1;
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int queueFront=s1.top();
        s1.pop();
        //wapis s1 mei daal do
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return queueFront;
    }
    
    int peek(){
        if(empty()) return -1;
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int queueFront=s1.top();
        s1.pop();
        s2.push(queueFront);
        //wapis s1 mei daal do
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return queueFront;
    }
    
    bool empty(){
        return (s1.size()==0);
    }
};

//Appraoch 2: O(1) ammortised
class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue(){}
    
    void push(int x){
        input.push(x);
    }
    
    int pop(){
        if(empty()) return -1;
        if(output.empty()){
            //input->output
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        //following steps are common in both cases of o/p empty/not
        int temp=output.top();
        output.pop();
        return temp;
    }
    
    int peek(){
        if(empty()) return -1;
        if(output.empty()){
            //input->output
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty(){
        return (input.empty() and output.empty());
    }
};