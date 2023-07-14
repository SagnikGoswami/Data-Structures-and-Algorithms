//So 100010 aur i=4 so basically agar
//   010000 iss number ke saath or lenge toh as 0 baaki toh same aur ith bit 1

void setithBit(int n,int i){
    n=(n|(1<<i));
}