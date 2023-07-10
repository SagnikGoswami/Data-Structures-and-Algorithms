//Can do one job in one day, aur jobs along with thier deadline and profit are 
//given need to figure out the maximum profit
#include <iostream>
using namespace std;
#include <bits/stdc++.h>  
class Job{
public:
    int deadline;
    int profit;
    Job(int deadline=0,int profit=0){
        this->deadline=deadline;
        this->profit=profit;
    }
};
class Compare{
public:
    bool operator()(const Job &job1,const Job &job2){
        //job1 and job2 in correct order if job1 has more
        //profit than job2
        return (job1.profit>job2.profit);
    }
};
vector<Job> getSortedJobs(vector<vector<int>> &jobs,int &maxDeadline){
    int n=jobs.size();
    vector<Job> tasks;
    for(int i=0;i<n;i++){
        int deadline=jobs[i][0];
        maxDeadline=max(maxDeadline,deadline);
        int profit=jobs[i][1];
        Job newJob(deadline,profit);
        tasks.push_back(newJob);
    }
    sort(tasks.begin(),tasks.end(),Compare());
    return tasks;
}
int fetchMaxProfit(vector<Job> &tasks,int maxDeadline){
    //Now to get answer we need to put the job as late as possible
    vector<int> slots(maxDeadline+1,-1); //-1 indicates slots[i]
    //is not yet occupied with a job
    int maxProfit=0;
    int n=tasks.size();
    for(int i=0;i<n;i++){
        int deadline=tasks[i].deadline;
        int profit=tasks[i].profit;
        for(int day=deadline;day>0;day--){
            //check if day is empty ie. -1 if yes then put
            if(slots[day]==-1){
                slots[day]=i;//ith task done on this day
                maxProfit=maxProfit+profit;
                break;//as found day now look for the day
                //for the next highest profit task
            }
        }
    }
    return maxProfit;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int maxDeadline=0;
    vector<Job> tasks=getSortedJobs(jobs,maxDeadline);
    //sort that according to profit as we want to perform the max
    //profit jobs first and then do the less profit once
    //Now do the job as late as possible ie. on deadline day
    //so that if there are high profitable jobs with lower deadline
    //we can perform those
    int profit=fetchMaxProfit(tasks,maxDeadline);
    return profit;
}
