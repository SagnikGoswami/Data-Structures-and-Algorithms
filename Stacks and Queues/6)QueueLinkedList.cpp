#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node *head=NULL;
Node *tail=NULL;
void push(int x){
    Node *newNode=new Node(x);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=tail->next;
    }
}

int pop() {
    if(head==NULL) return -1;
    Node *temp=head;
    int front=temp->data;
    head=head->next;
    temp->next=NULL;
    delete temp;
    return front;
}