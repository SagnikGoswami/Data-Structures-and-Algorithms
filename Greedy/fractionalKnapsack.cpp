#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
class Item{
public:
    int weight;
    int profit;
    double profitPerUnitWeight;
    Item(int weight,int profit,double profitPerUnitWeight){
        this->weight=weight;
        this->profit=profit;
        this->profitPerUnitWeight=profitPerUnitWeight;
    }
}; 
class Compare{
public:
    bool operator()(const Item &item1,const Item &item2){
        //item1 item2 in correct order or not => decreasing order of profit by weight
        return (item1.profitPerUnitWeight>item2.profitPerUnitWeight);
    }
};
vector<Item> getObjects(vector<pair<int,int>> &items,int n){
    vector<Item> objects;
    for(int i=0;i<n;i++){
        int weight=items[i].first;
        int profit=items[i].second;
        double profitPerWeight=(double)profit/weight;
        Item newItem(weight,profit,profitPerWeight);
        objects.push_back(newItem);
    }
    sort(objects.begin(),objects.end(),Compare());
    return objects;
}
vector<double> getFraction(vector<Item> &objects,int w,int n){
    vector<double> fraction(n,0);
    for(int i=0;i<n;i++){
        int weight=objects[i].weight;
        if(weight<=w){
            //means can add the whole object into the bag
            fraction[i]=1;//as whole can apply
            w=w-weight;//can store more w things
        }
        else if(weight>w){
            //means have to take fraction
            double objectFraction=(double)w/weight;
            fraction[i]=objectFraction;
            break;//remaining can't add
        }
    }
    return fraction;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    //Selection Criteria of any object is to maximize the profit
    //with min increase in weight of bag so maximize profit/weight
    vector<Item> objects=getObjects(items,n);
    vector<double> fraction=getFraction(objects,w,n);//get how much fraction of each object we should take to max
    //our profit
    double maxProfit=0;
    for(int i=0;i<n;i++){
        double profit=objects[i].profit*fraction[i];
        maxProfit+=profit;
    }
    return maxProfit;
}