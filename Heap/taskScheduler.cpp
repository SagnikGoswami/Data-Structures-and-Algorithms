// idea is n=2 then A _ _ in blanks mei A noi aa skta so we can say
// any character can come in _ _ _ mei se ek mei hi ie. (n+1) places
// mei se kisi ek mei aayega ek character

// and AAABBCC clearly saare task same priority ke as nothing mentioned
// about individual tasks, but agar most frequent(at any instance) 
// wallo ko jaldi kre then min time lag as then last mei woh bht saare bach 
// then  due to idle time wastage of time

// So priority given to frequency of tasks currently so make maxHeap
// so that max priority task can get as fast as possible

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

typedef pair<int,char> taskFreq; //freq,task 

class Solution{
private:
    unordered_map<char,int> getFrequency(vector<char> &tasks){
        unordered_map<char,int> freq;
        for(auto it : tasks) freq[it]++;
        return freq;
    }
    void insertIntoHeap(priority_queue<taskFreq> &maxHeap,unordered_map<char,int> &freq){
        for(auto it : freq){
            int frequency=it.second;
            char task=it.first;
            maxHeap.push({frequency,task});
        }
    }
public:
    int leastInterval(vector<char>& tasks,int n){
        priority_queue<taskFreq> maxHeap; //character push to track which task
        //firstly we would need initial frequency of all tasks
        unordered_map<char,int> freq=getFrequency(tasks);
        //Now, we push all the frequencies to unordered map
        insertIntoHeap(maxHeap,freq);
        //Now what we do is if the freq of a task ie. number of task
        //remaining to get done is non zero then we push that back
        //along with the reduced number of task into the heap
        //and if freq!=0 then not push into heap so if heap is
        //empty then no tasks left so got the minTime
        int minTime=0;
        string taskOrder="";
        while(maxHeap.empty()==false){
            //Now we need to make sure that a task should not occur
            //Again in n+1 time interval
            //So we maintain a vector(helper) to store the elements
            //already executed in the current n+1 time cycle along with freq
            vector<taskFreq> helper;
            for(int clockCycle=0;clockCycle<n+1;clockCycle++){
                if(maxHeap.empty()==false){
                    //need to make sure this in every iteration
                    char mostFrequentTask=maxHeap.top().second;
                    int currentFreq=maxHeap.top().first;
                    maxHeap.pop();
                    taskOrder=taskOrder+" "+mostFrequentTask;
                    if(currentFreq>1) helper.push_back({currentFreq-1,mostFrequentTask});
                    //minus 1 as 1 task already done in current iteration
                    //and check >1 as if 1 then all tasks are done
                    minTime++;
                }
                else if(maxHeap.empty()==true and helper.size()>0){
                    //means we have more tasks to be done
                    //so we can add to the total time even if heap is empty/not empty
                    //as then that would be becoz we could not add same
                    //chars in the n+1 cycle
                    taskOrder+=" idle";
                    minTime++; //these are the idle times added
                }
            }
            //again pushing the poped out back to heap
            for(auto it : helper){
                maxHeap.push(it);
            }
        }
        cout<<taskOrder<<endl;
        return minTime;
    }
};