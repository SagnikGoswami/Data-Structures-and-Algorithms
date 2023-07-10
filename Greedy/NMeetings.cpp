#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
//Selection criteria is joh input(meetings) kam time legi unko
//select kr lenge aur answer mei daal denge
//Iss selection criteria ko throughout follow

//Agar woh mettings kar le joh pehle khtm toh unke khtm hone ke baad
//more meetings kar paayenge so can maximize

class Meeting{
public:
    int startTime;
    int endTime;
    int meetingNumber;
    Meeting(int startTime=0,int endTime=0,int meetingNumber=0){
        this->startTime=startTime;
        this->endTime=endTime;
        this->meetingNumber=meetingNumber;
    }
};
 
class Compare{
public:
    bool operator()(const Meeting &m1,const Meeting &m2){
        //check if m1 m2 in correct position ie. m1<m2
        if(m1.endTime<m2.endTime) return true;//1st priority to smaller end time
        else if(m1.endTime>m2.endTime) return false;
        else if(m1.meetingNumber<m2.meetingNumber){
            return true;
        }
        return false;
    }
};
vector<int> maximumMeetings(vector<int> &start,vector<int> &end){
    int n=start.size();
    vector<Meeting> meetings;
    //Now, we insert {start,end,index+1(1 based indexing)} into our array
    for(int i=0;i<n;i++){
        Meeting newMeeting(start[i],end[i],i+1);
        meetings.push_back(newMeeting);
    }
    //Now, we sort
    sort(meetings.begin(),meetings.end(),Compare());
    //Now we pick up those meetings one by one which start
    //at a time after the ending time of previous meeting
    int prevEndTime=-1;
    vector<int> answer;
    for(auto it : meetings){
        int startingTime=it.startTime;
        int endingTime=it.endTime;
        int meetingNumber=it.meetingNumber;
        if(prevEndTime<startingTime){
            answer.push_back(meetingNumber);
            prevEndTime=endingTime;
        }
    }
    return answer;
}