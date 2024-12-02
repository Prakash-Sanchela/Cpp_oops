#include<stdio.h> 
// 10 - 0000 1010
// pos1 = 1
// pos2 = 4
// After swap 
// 24 - 0001 1000
void swap_bits(int num, int pos1, int pos2)
{
    int mask1,mask2;
    int bit= (num>>pos1)&1;
    int bit1= (num>>pos2)&1;
    if(bit!=bit1)
    {
      num^=(1<<pos1);
      num^=(1<<pos2);
    }
    printf("%d ",num);
}
int main()
{
	swap_bits(10, 1, 4);
}
