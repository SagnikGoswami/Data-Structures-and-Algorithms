#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
public:
    Node* links[2];
    Node(){
        this->links[0]=NULL;
        this->links[1]=NULL;
    }

    bool contains(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node *newNode){
        links[bit]=newNode;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private:
    Node *root;
public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node *node=root;//traversal walla node
        //insert the binary representation of num(from MSB-->LSB)
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;//0 if ith bit is 0 else 1
            if(node->contains(bit)==false){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node *node=root;
        int maximumXor=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int compliment=!bit;
            if(node->contains(compliment)==true){
                node=node->get(compliment);
                maximumXor=maximumXor|(1<<i);//as agar opposite exist then can 
                //make ith bit of xor 1
            }
            else node=node->get(bit);
        }
        return maximumXor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it : nums) trie.insert(it);
        int maximumXor=0;
        for(auto it : nums){
            int tempMaximumXor=trie.getMax(it);
            maximumXor=max(maximumXor,tempMaximumXor);
        }
        return maximumXor;
    }
};