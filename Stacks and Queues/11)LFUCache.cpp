#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
//Doubly Linked List Node
class Node{
public:
//data members
    int key;
    int val;
    int nodeFreq;
    Node *prev;
    Node *next;
//constructor
    Node(int key=-1,int val=-1,int nodeFreq=1){
        this->key=key;
        this->val=val;
        this->nodeFreq=nodeFreq;
        this->prev=NULL;
        this->next=NULL;
    }
};
//List class ie. ek freq ke corresponding ek DLL whi list yeh
class List{
public:
//data members
    Node *head;
    Node *tail;
    int listSize;
//constructor
    List(){
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        listSize=0;
    }
//methods
    void removeNode(Node *node){
        Node *prevNode=node->prev,*nextNode=node->next;
        prevNode->next=nextNode,nextNode->prev=prevNode;
        node->next=NULL,node->prev=NULL;
        listSize--;
    }
    void insertNode(Node *node){
        Node *prevMostRecentlyUsed=head->next;
        head->next=node,node->prev=head;
        node->next=prevMostRecentlyUsed,prevMostRecentlyUsed->prev=node;
        listSize++;
    }
};
class LFUCache{
private:
//data members
    unordered_map<int,List> freqList;
    unordered_map<int,Node*> keyNode;
    int minFreq;
    int capacity;
//private methods
    void updateFreqList(Node *reqNode){
        //pehle purane freq walle list se hatao(links break krdo)
        int prevFreq=reqNode->nodeFreq;
        freqList[prevFreq].removeNode(reqNode);
        if(prevFreq==minFreq and freqList[prevFreq].listSize==0) minFreq=prevFreq+1;//as then no nodes in prevFreq walla list
        reqNode->nodeFreq++;
        freqList[prevFreq+1].insertNode(reqNode);//insert to new list the node
    }
public:
    LFUCache(int capacity){
        minFreq=0;
        this->capacity=capacity;
    }
    
    int get(int key){
        if(keyNode.count(key)){
            //means key is present in the list kisi freq par to hai
            Node *reqNode=keyNode[key];
            updateFreqList(reqNode);
            return reqNode->val;
        }
        else return -1;
    }
    
    void put(int key,int value){
        if(keyNode.count(key)){
            //ie. previously exists so we update the freqList and the value
            Node *reqNode=keyNode[key];
            reqNode->val=value;//updated the value
            updateFreqList(reqNode);
            return;
        }
        else if(!keyNode.count(key) and keyNode.size()==capacity){
            //LFU walle list mei se LRU hatao
            Node *leastRecentlyUsed=freqList[minFreq].tail->prev;
            freqList[minFreq].removeNode(leastRecentlyUsed);
            keyNode.erase(leastRecentlyUsed->key);
            delete leastRecentlyUsed;
        }
        Node *newNode=new Node(key,value);
        keyNode[key]=newNode;
        minFreq=1;//surely it will be 1 as new Node is inserted
        freqList[1].insertNode(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */