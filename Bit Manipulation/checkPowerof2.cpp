//check if n is power of 2
//clearly ek hi set bit aur usko remove kr denge to 0 ban jaayega

bool isPower2(int n){
    return (n&(n-1))==0;
}