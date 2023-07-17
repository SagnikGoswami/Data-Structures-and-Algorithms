#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
//data members
    Node* links[26];
    Node(){
        for(int i=0;i<26;i++){
            this->links[i]=NULL;
        }
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
};

int countDistinctSubstrings(string &s){
    int n=s.size();
    Node *root=new Node();
    int count=0;
    for(int i=0;i<n;i++){
        Node *node=root;
        for(int j=i;j<n;j++){
            char ch=s[j];
            if(node->contains(ch)==false){
                count++;
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
    }
    return count+1;
}