bool isOdd(int n){
    //Odd hai toh last bit set hoga
    //So agar 1 se & lenge toh result 1 dega
    //  ....1(for odd)
    //& 00001 so 1 hi dega aur even =>last bit bhi 0 so 0
    return ((n&1)==1);//fastest way to check odd
}