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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        vector<vector<int>> offlineQueries;
        int q=queries.size();
        for(int i=0;i<q;i++){
            int xi=queries[i][0];
            int mi=queries[i][1];
            offlineQueries.push_back({mi,xi,i});//as sort wrt mi
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        Trie trie;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> answer(q);
        int it_nums=0;//iterator on nums
        for(int i=0;i<q;i++){
            int mi=offlineQueries[i][0];
            int xi=offlineQueries[i][1];
            int ind=offlineQueries[i][2];
            int maxXor=-1;//as no such then -1 hi
            while(it_nums<n and nums[it_nums]<=mi){
                trie.insert(nums[it_nums]);
                it_nums++;
            }
            if(it_nums!=0) maxXor=trie.getMax(xi);
            answer[ind]=maxXor;
        }
        return answer;
    }
};