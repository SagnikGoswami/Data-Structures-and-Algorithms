#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Twitter {
private:
    int timer; //keeps track of which tweet before which tweet
    unordered_map<int,unordered_set<int>> follower; //key=userID and value will be all the users he follows
    priority_queue<pair<int,pair<int,int>>> recentTweets; //stores the most recently done tweets along with tweet and user
    //so that we can get the top 10 tweets very fast
public:
    Twitter(){
        timer=0; //set to 0 as this marks the begining of our app
    }
    
    void postTweet(int userId,int tweetId){
        //Now we postTweet so timer increases and we push that to recentTweets
        recentTweets.push({timer,{tweetId,userId}});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId){
        vector<pair<int,pair<int,int>>> helper; //this will store all the tweets poped out so that we can push them again
        vector<int> tweets;
        int countTweets=0;
        while(recentTweets.empty()==false and countTweets<10){
            int user=recentTweets.top().second.second;
            int tweetId=recentTweets.top().second.first;
            helper.push_back(recentTweets.top());
            recentTweets.pop();
            //check if userId follows user or not or post khud user nei kiya ki nahi
            if(userId==user or follower[userId].count(user)!=0){
                //means does follow so we take that to answer
                tweets.push_back(tweetId);
                countTweets++;
            }
        }
        //Now wapis push to heap saare popped out ko
        for(auto it : helper) recentTweets.push(it);
        return tweets;
    }
    
    void follow(int followerId,int followeeId){
        follower[followerId].insert(followeeId); //indicating started following
    }
    
    void unfollow(int followerId,int followeeId) {
        follower[followerId].erase(followeeId); //indicating that removed from follower
    }
};