//Joh bhi least significant set bit usko remove

//Clearly a number's last set bit is 3 means 2^3 ie. 8 is the last power of
//2 jisko add krne se number ban
//as binary to decimal is additon of powers of 2
//So eg 24 ie. 16+8 ie. 11000 aise so last bit 8
//Now agar number se 1 ghataye then using concept ki
//8-1=7 so pehle 1000 ab 0111 ho ja ie. woh bit 0 ho ja and rest 111 uske pehle
//aur 3rd bit se pehle n-1 mei same ie. 
//24 => 11000 hai aur 23 => 10111 hai ie. last set bit ke age ka same
//Sa agar & lenge toh perfectly what we desire happens 

void removeLastSetBit(int n){
    n=n&(n-1);
}