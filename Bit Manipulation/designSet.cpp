//set mei elements allowed till 60 design set such that O(1) time and space
//for the following operations:
// 1. add(x) 2. remove(x) 3. printElem()

#include <iostream>
using namespace std;

class Set{
    //Clearly agar long long x lenge toh usmei 64 bits and woh can be
    //used where ith bit = 1 represents number is present aur 0 means not
private:
    long long x;
public:
    Set(){
        this->x=0;
    }
    void add(int num){
        //000000000000100000 aur x=4 aaya so need to set 4th bit rest same
        //000000000000010000 iss number se agar | lenge toh done
        x=x|(1<<num);
    }
    void remove(int num){
        //000001000 aur remove 3 bola bol so unset kro hence & lenge with
        //111110111 aur done so ~(1<<num) se &
        x=x&(~(1<<num));
    }
    void print(){
        //iterate thru the set and if found set hai bit so print bit number
        for(int bit=0;bit<=60;bit++){
            if(x&(1<<bit)) cout<<bit<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Set st;
    st.add(5);
    st.add(4);
    st.add(7);
    st.add(4);
    st.print();
    st.add(5);
    st.remove(5);
    st.print();
    st.add(12);
    st.add(16);
    st.add(1);
    st.print();
    st.remove(4);
    st.print();
}