#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
    Node* links[26];
    int cntEndsWith;
    int cntPrefix;
    Node(){
        for(int i=0;i<26;i++){
            this->links[i]=NULL;
        }
        this->cntEndsWith=0;
        this->cntPrefix=0;
    }

    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *newNode){
        links[ch-'a']=newNode;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void increaseEndsWith(){
        cntEndsWith++;
    }
    int getcntEndsWith(){
        return cntEndsWith;
    }
    int getcntPrefix(){
        return cntPrefix;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    void reduceEndsWith(){
        cntEndsWith--;
    }
};
class Trie{
private:
    Node *root;
public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node *node=root;
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++){
            char ch=word[i];
            if(node->contains(ch)==false){
                Node *newNode=new Node();
                node->put(ch,newNode);
            }
            node=node->get(ch);
            node->increasePrefix();
        }
        node->increaseEndsWith();
    }

    int countWordsEqualTo(string &word){
        Node *node=root;
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++){
            char ch=word[i];
            if(node->contains(ch)==false) return 0;
            node=node->get(ch);
        }
        return node->getcntEndsWith();//NULL wgera check not need as not end toh 0 hoga cntEnds with mei
    }

    int countWordsStartingWith(string &word){
        Node *node=root;
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++){
            char ch=word[i];
            if(node->contains(ch)==false) return 0;
            node=node->get(ch);
        }
        return node->getcntPrefix();
    }

    void erase(string &word){
        Node *node=root;
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++){
            char ch=word[i];
            if(node->contains(ch)==false) return;
            node=node->get(ch);
            node->reducePrefix();
        }
        node->reduceEndsWith();
    }
};
