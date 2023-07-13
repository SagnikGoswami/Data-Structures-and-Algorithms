//Saare k size subarray mei se maximum nikal ke answer mei push aur return

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums,int k){
        int n=nums.size();
        int startInd=0,endInd=0;
        vector<int> answer;
        set<pair<int,int>> st;//{number,index} store all the numbers in the window in set so that we can get the
        //max from the end of set and also can remove the startInd number easily while sliding the window
        while(endInd<n){
            //calculation wrt endInd, simply insert in the set
            st.insert({nums[endInd],endInd});
            int windowSize=endInd-startInd+1;
            //case 1
            if(windowSize<k) endInd++;
            //case 2
            else if(windowSize==k){
                //Find the answer wrt the calculations done
                pair<int,int> maxEleWindow=*st.rbegin();
                int maxEle=maxEleWindow.first;
                answer.push_back(maxEle);
                //slide the window
                st.erase({nums[startInd],startInd});
                startInd++,endInd++;
            }
        }
        return answer;
    }
};

//Approach 2: O(n) walla
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums,int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        int endInd=0;
        while(endInd<n){
            if(dq.empty()==false and dq.front()==endInd-k){
                //means out of bound value rkha hua dq ke front mei
                dq.pop_front();
            }
            //Calculations wrt endInd

            //Now, we remove all the elements smaller than 
            //the end index from the back of deque as they are of no
            //use now as end index will come in window from now onwards
            //and it will be the more than all others in window till
            //now so we remove them
            while(dq.empty()==false and nums[dq.back()]<=nums[endInd]){
                dq.pop_back();
            }
            //Now we can push the endInd
            dq.push_back(endInd);
            if(endInd<k-1) endInd++;//as then we don't have a k sized window
            //till now then
            else if(endInd>=k-1){
                //this endInd onwards we have k sized windows

                //use the calculations done to update answer
                //Clearly the max of window is kept at the front of dq
                //this is becoz as we removed all the smaller than front
                //then pushed the end and if front se badha
                //koi aur milta uske baad to woh usko dq se nikal deta
                ans.push_back(nums[dq.front()]);
                //Now slide the window no start index here just end index
                endInd++;//start index walla out of bound
                //case is dealt at the start before doing calculations
                //wrt start
            }
        }
        return ans;
    }
};