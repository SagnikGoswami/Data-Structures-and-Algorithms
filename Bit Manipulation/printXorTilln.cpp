//Given n we need to print xor of 1 till n in O(1)

//Pattern observe kro
int xorTilln(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
}

//Follow up is L to R sabka xor leke answer batao
//Clearly till (L-1) ka xor (R) tak ke xor se cancel karna
//same number se xor lene se cancel so xor(L-1)^xor(R) above function ka use kro