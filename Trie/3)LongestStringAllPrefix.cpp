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

    bool hasAllPrefix(string word){
        int wordLen=word.size();
        Node *node=root;
        bool flag=true;
        for(int i=0;i<wordLen;i++){
            char ch=word[i];
            if(node->contains(ch)==true){
                node=node->get(ch);
                flag=flag&(node->isEnd());
            }
            else return false;
        }
        return flag;
    }
};
string completeString(int n,vector<string> &a){
    Trie trie;
    string longest="";
    for(auto it : a) trie.insert(it);
    for(auto it : a){
        if(trie.hasAllPrefix(it)==true){
            if(it.size()>longest.size()){
                longest=it;
            }
            else if(it.size()==longest.size() and it<longest){
                longest=it;
            }
        }
    }
    if(longest=="") return "None";
    else return longest;
}