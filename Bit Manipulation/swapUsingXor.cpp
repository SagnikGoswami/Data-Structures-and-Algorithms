void swap(int &num1,int &num2){
    num1=num1^num2; //num1=5^6 num2=6
    num2=num1^num2; //num1=5^6 num2=(5^6)^6 so 6 and 6 cancel=5
    num1=num1^num2; //num1=5^6^5=6(as associative)
}