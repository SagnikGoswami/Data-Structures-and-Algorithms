//So ith bit joh bhi usko 0 bana 
// 0010101 i=3 clearly
// 1110111 iske saath & lenge toh baaki as it is and ith bit 0 ho ja
//this is ~(mask)

void clearithBit(int n,int i){
    n=n&(~(1<<i));
}