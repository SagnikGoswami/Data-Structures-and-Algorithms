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
class Stack
{
private:
    Node *head;
    int size;//number of nodes inserted

public:
    Stack()
    {
        head=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size==0);
    }

    void push(int data)
    {
        Node *newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void pop()
    {
        if(isEmpty()) return;
        Node *temp=head;//to delete
        head=head->next;
        temp->next=NULL;//taaki destructor apne saath sabko na le jaye
        delete temp;
        size--;
    }

    int getTop()
    {
        if(isEmpty()) return -1;
        return head->data;
    }
};