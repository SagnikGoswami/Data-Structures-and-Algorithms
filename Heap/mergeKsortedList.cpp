#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// k list given saare sorted, so need to merge into a single list

// k list ke first element mei se smallest walla hoga list ka first ele
// so k numbers se min fastest nikalna hence min heap
// but store the element along with its value
// key value hi hoga
// jaise hi ek element main list mei push woh uske next
// mei point krne lgega 

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef pair<int,ListNode*> p;
ListNode* dummy=new ListNode(0);
ListNode* tail=dummy;

ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<p,vector<p>,greater<p>> minHeap;
    for(ListNode* it : lists){
        if(it==NULL) continue;
        minHeap.push({it->val,it});
    }
    //So now all the starting points pushed into heap
    while(minHeap.empty()==false){
        ListNode* minEle=minHeap.top().second;
        minHeap.pop();
        tail->next=minEle;
        tail=tail->next;
        ListNode* next=minEle->next;
        if(next!=NULL){
            minHeap.push({next->val,next});
        }
    }
    return dummy->next;
}