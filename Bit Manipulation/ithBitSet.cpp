//Check if ith bit of number set or not
//  00001010 i=3 then yes set hai check by
//  00001000 agar aisa koi number aur & lenge so 0 => not set
//  this number is called mask 1<<i left shift kro

bool ithBitSet(int n,int i){
    return (n&(1<<i)); //so agar non 0 so true return krega
}
//Follow up is to check what is present in ith bit so same hi agar yeh return true
//means 1 else false