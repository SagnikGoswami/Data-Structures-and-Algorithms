#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
//data members
    Node* links[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++){
            this->links[i]=NULL;
        }
        this->flag=false;
    }
//methods
    bool contains(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *newNode){
        links[ch-'a']=newNode;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return (flag==true);
    }
};
class Trie {
private:
    Node *root;
public:
    Trie(){
        root=new Node();
    }
    
    void insert(string word){
        Node *node=root;
        int wordLen=word.size();
        for(int i=0;i<wordLen;i++){
            int ch=word[i];
            if(node->contains(ch)==false){
                Node *newNode=new Node();
                node->put(ch,newNode);
            }
            node=node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word){
        Node *node=root;
        int wordLen=word.size();
        for(int i=0;i<wordLen;i++){
            int ch=word[i];
            if(node->contains(ch)==false) return false;
            node=node->get(ch);
        }
        return (node->isEnd());
    }
    
    bool startsWith(string prefix){
        Node *node=root;
        int prefixLen=prefix.size();
        for(int i=0;i<prefixLen;i++){
            int ch=prefix[i];
            if(node->contains(ch)==false) return false;
            node=node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */