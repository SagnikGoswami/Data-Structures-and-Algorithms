#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
//Doubly Linked List Node
class Node{
public:
//data members
    int key;
    int val;
    Node *prev;
    Node *next;
//constructor
    Node(int key=-1,int val=-1){
        //dummy value (-1,-1)
        this->key=key;
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};
class LRUCache{
private:
//data members
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int,Node*> keyNode;//{key and corresponding node}

//private functions
    void deleteNode(Node *node){
        Node *prevNode=node->prev,*nextNode=node->next;
        prevNode->next=nextNode,nextNode->prev=prevNode;
        node->next=NULL,node->prev=NULL;//taaki apne saath baakiyo ko bhi na leke jaaye
        int nodeKey=node->key;
        keyNode.erase(nodeKey);//remove from unordered map as well
        delete node;
    }
    void insertNode(Node *newNode){
        Node *prevMostRecentlyUsed=head->next;
        head->next=newNode,newNode->prev=head;
        newNode->next=prevMostRecentlyUsed,prevMostRecentlyUsed->prev=newNode;
        keyNode[newNode->key]=head->next;
    }
public:
    LRUCache(int capacity){
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
    }
    
    int get(int key){
        if(keyNode.count(key)){
            //means it is present
            //We get the value to return and make it the most frequently used
            Node *node=keyNode[key];
            int data=node->val;//return this
            deleteNode(node);//delete the entry from unordered map and Linked List
            Node *newNode=new Node(key,data);
            insertNode(newNode);//insert node right next to head and make entry in the map with new address(head->next)
            return data;
        }
        else return -1;//as not present
    }
    
    void put(int key,int value){
        if(keyNode.count(key)){
            //means present from before so update the value ie. delete previous node and insert with new value
            Node *node=keyNode[key];
            deleteNode(node);
        }
        else if(!keyNode.count(key) and keyNode.size()==capacity){
            Node *leastRecentlyUsed=tail->prev;
            deleteNode(leastRecentlyUsed);
        }
        Node *newNode=new Node(key,value);
        insertNode(newNode);
    }
};