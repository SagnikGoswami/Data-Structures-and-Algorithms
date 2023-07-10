#include <iostream>
using namespace std;

// Idea is a bucket array lenge now any string ka corresponding integer want
// so that usko uss bucket array mei daal ske
// key --> [HASH FUNCTION] --> integer --> [Compression Function] => index of bucket array
// HASH FUNCTION should be such that the integer coming out is 
// uniformly distributed throughtout range, aisa nahi ki ek hi jagh aa rhe
// Same integer 2 keys then linked list make so har bucket array
// iss linked list head pe point (chaining/closed hashing technique of collision handling)
// Now we want ki size/bucketSize < 0.7 so that O(1) ho approx Time complexity
// this is becoz on an average each cell is size/bucketSize long linked list
// So size double of bucket and reshash krenge

template <class T> //value can be of any type
class MapNode{
public:
    string key;
    T value;
    MapNode* next;
    MapNode(string key,T value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
    ~MapNode(){
        delete next; //recursively done
    }
};
template <class T>
class Map{
private:
    MapNode<T> **buckets; //as each element is pointer to head of LL
    int count; //kitne elements bucket mei aa chuke
    int bucketSize;
    double threshold=0.7; //threshold for rehashing aur static as class ka property
    int getBucketIndex(string &key){
        //Pehle humara hash function se pass then compression function=%bucketSize
        //abcd=>a*(37^3)+b*(37^2)+c*(37^1)+d will be hash function
        int size=key.size();
        int base=1;
        int hash=0;
        for(int i=size-1;i>=0;i--){
            int ascii=key[i];
            hash=(ascii*base)%(bucketSize); //as int se bht jldi bahar ja
            base=(base*37)%(bucketSize); //update for next LSB
        }
        //Now pass through compression function
        return hash%bucketSize;
    }
    void rehash(){
        //we first create a new bucket array of double size and then
        //ek ek karke purane walle se data daal de
        MapNode<T> **prevBucket=buckets;
        buckets=new MapNode<T>*[bucketSize*2];
        int oldBucketSize=bucketSize;
        bucketSize=bucketSize*2;
        for(int i=0;i<bucketSize;i++) buckets[i]=NULL;
        count=0; //as wapis se insert krenge sabko so count badh
        //ie. poora situation make ki map mei kuch noi
        for(int i=0;i<oldBucketSize;i++){
            MapNode<T> *head=prevBucket[i];
            while(head!=NULL){
                string key=head->key;
                T value=head->value;
                insert(key,value); //now as bucket changed so new bucket mei 
                //jake insert honge
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketSize;i++){
            delete prevBucket[i];
        }
        delete []prevBucket;
    }
public:
    Map(){
        //initialize humare data members ko
        count=0; //initially no elements
        bucketSize=5;//initially 5 le
        buckets=new MapNode<T>*[bucketSize];
        //Now sab jagah null krna as random pointers bht dangerous h
        for(int i=0;i<bucketSize;i++){
            buckets[i]=NULL;
        }
    }
    ~Map(){
        //first delete all the linked list
        for(int i=0;i<bucketSize;i++){
            delete buckets[i];
        }
        //now delete the bucket array
        delete []buckets;
    }
    int size(){
        return count;
    }
    void insert(string key,T value){
        //Now 1st kaam is to identify the bucket index
        int bucketIndex=getBucketIndex(key);
        //first need to check kahi pehle se key exist to nahi krta
        MapNode<T> *head=buckets[bucketIndex];
        MapNode<T> *temp=head;//traverse uss LL so that can check
        while(temp!=NULL){
            if(temp->key==key){
                //means found so just update the value
                temp->value=value;
                return;
            }
            temp=temp->next;
        }
        //reached here means nahi mila so insert starting mei
        MapNode<T> *newNode=new MapNode<T>(key,value);
        if(head!=NULL) newNode->next=head->next;
        buckets[bucketIndex]=newNode; //so yeh new head ban ja
        count++;
        //Now check if Load Factor crossed threshold or not
        double LoadFactor=(double)count/bucketSize;
        if(LoadFactor>threshold) rehash(); //then rehash kr denge

    }
    T remove(string key){
        //Find the key so index need corresponding needed
        int bucketIndex=getBucketIndex(key);
        MapNode<T> *head=buckets[bucketIndex];
        MapNode<T> *prev=NULL; //Whi linked list node delete technique so prev needed
        while(head!=NULL){
            if(head->key==key){
                //now agar prev bhi NULL hua to head hi apna key
                if(prev==NULL) buckets[bucketIndex]=head->next;
                //baaki neeche walle kaam har case mei
                MapNode<T> *node=head;
                T temp=head->value;// to return
                if(prev!=NULL) prev->next=node->next;
                //Now node ko delete so destructor saare aage wallo
                //ko bhi delete
                node->next=NULL; //thus yeh kr
                count--;
                delete node;
                return temp;
            }
            prev=head;
            head=head->next;
        }
        //reach here means no key found
        return 0;
    }
    T getValue(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<T> *head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key) return head->value;
            head=head->next;
        }
        return 0; //key not found
    }
};
int main(){
    Map<int> test;
    test.insert("me",10);
    test.insert("cs",99);
    test.insert("ai",95);
    test.insert("tt",12);
    test.remove("cs");
    cout<<test.size()<<endl;
}