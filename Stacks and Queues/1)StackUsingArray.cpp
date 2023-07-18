// Stack class.
class Stack {
private:
    int *container;//ie. to store the elements
    int topPointer;//pointer to the top element
    int capacity;//itna store kar skta
    
public:
    
    Stack(int capacity){
        this->capacity=capacity;
        container=new int[capacity];
        topPointer=-1;//intially donot point to any element(internally top points to index of array storing top)
    }

    void push(int num){
        //check ki full hai/not
        if(isFull()) return;//ie. last index of array mei top points means array full
        container[topPointer+1]=num;//next to top push kr diya
        topPointer++;//new position of top is the next element
    }

    int pop(){
        //check if empty/not
        if(isEmpty()) return -1;//as then empty hoga
        int temp=container[topPointer];
        topPointer--;//bass -- as humare consideration mei stack topPointertak hi hai so no need
        //to erase the previous top value as woh ab bound ke bahar chla gya
        return temp;
    }
    
    int top(){
        if(isEmpty()) return -1;//as then empty
        return container[topPointer];
    }
    
    int isEmpty(){
        return (topPointer==-1);
    }
    
    int isFull(){
        return (topPointer==capacity-1);
    }
    
};