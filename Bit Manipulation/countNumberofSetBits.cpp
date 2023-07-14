//Need to traverse throught the bits aur count if it is set or not
//way to traverse is n=n>>1 1 se right shift krte jao
//so saare bit ek iteration mei LSB mei aa jayenge so inko count krlo

int countSetBits(int n){
    int count=0;
    while(n){
        //jab tak n 0 noi ho jaata ie. all the bits traversed as >> hote
        //hote koi set bit bacha noi sab right mei dustbin
        if(n&1) count++; //as agar 0 hota to n&1 will be 0 hence count noi
        n=n>>1;
    }
    return count;
}