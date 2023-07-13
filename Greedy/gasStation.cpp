//Approach -> as guareented ki answer unique so exist hi so agar 
//koi start se noi pahuch pa till an index then pakka
//that woh start not answer as woh agar answer hota to hume end 
//tak pahucha deta pakke se
//Also index+1 se check krna start kar as start to index toh pakka noi
//as fuel>=0 tha tabhi reach index so agar 
//positive fuel ke saath bhi beech walle noi surpass the index
//then to pakke se agar wha se start kro ie. fuel=0 toh noi reach
//poora cycle noi ghum

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,vector<int>& cost) {
        int totalSurplus=0;//to keep track of Σgas-Σcost overall start to end agar whi negative so answer is 0
        int currSurplus=0;
        int n=gas.size();
        int startingPoint=0;
        for(int station=0;station<n;station++){
            int extraFuel=gas[station]-cost[station];
            totalSurplus+=extraFuel;
            currSurplus+=extraFuel;
            if(currSurplus<0){
                //need to restrat as startingPoint then not valid
                startingPoint=station+1;
                currSurplus=0;
            }
        }
        if(totalSurplus<0) return -1;
        else return startingPoint;
    }
};