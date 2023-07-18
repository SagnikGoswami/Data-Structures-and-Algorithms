#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Approach 1: Time : push O(1) and pop O(n) Space O(2n)
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;//dono mei se koi queue mei honge saare elements
public:
    MyStack(){
        //do nothing as yeh q1 aur q2 ko baas set up kr denge
    }
    
    void push(int x){
        //O(1) walla hoga same as stack
        //jiss queue mei currently elements usmei daalenge 
        if(q1.empty()) q2.push(x);
        else q1.push(x);
    }
    
    int pop(){
        if(empty()) return -1;
        //Now till not get 1 element pop aur dusre queue mei daal
        if(q1.empty()){
            //means q2 se pop krke q1 mei daalna
            while(q2.size()>1){
                int frontElem=q2.front();
                q2.pop();
                q1.push(frontElem);
            }
            //Now q2 ka size 1 means we have last element inserted ie. stack ka top
            int lastElem=q2.front();
            q2.pop();
            return lastElem;      
        }
        else{
            //means q1 se pop krke q1 mei daalna
            while(q1.size()>1){
                int frontElem=q1.front();
                q1.pop();
                q2.push(frontElem);
            }
            //Now q2 ka size 1 means we have last element inserted ie. stack ka top
            int lastElem=q1.front();
            q1.pop();
            return lastElem; 
        }
    }
    
    int top(){
        if(empty()) return -1;
        //Now till not get 1 element pop aur dusre queue mei daal
        if(q1.empty()){
            //means q2 se pop krke q1 mei daalna
            while(q2.size()>1){
                int frontElem=q2.front();
                q2.pop();
                q1.push(frontElem);
            }
            //Now q2 ka size 1 means we have last element inserted ie. stack ka top
            int lastElem=q2.front();
            q2.pop();
            q1.push(lastElem);
            return lastElem;      
        }
        else{
            //means q1 se pop krke q1 mei daalna
            while(q1.size()>1){
                int frontElem=q1.front();
                q1.pop();
                q2.push(frontElem);
            }
            //Now q2 ka size 1 means we have last element inserted ie. stack ka top
            int lastElem=q1.front();
            q1.pop();
            q2.push(lastElem);
            return lastElem; 
        }
    }
    
    bool empty(){
        return (q1.empty() and q2.empty());
    }
};

//Approach 2: Using 1 queue
class MyStack {
private:
    queue<int> q;
public:
    MyStack(){}
    
    void push(int x){
        q.push(x);
        int size=q.size();
        for(int i=0;i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop(){
        if(q.empty()) return -1;
        int temp=q.front();
        q.pop();
        return temp;  
    }
    
    int top(){
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty(){
        return (q.size()==0);
    }
};