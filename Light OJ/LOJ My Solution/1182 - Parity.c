#include <stdio.h>

int main()
{
     int tc,cn = 1,n,count;

     scanf("%d", &tc);
     while( tc-- ){
          scanf("%d", &n);

          count = n % 2;
          while(n > 0){
              n = n >> 1;//Bit Right Shift by 1 place
              if(n % 2 == 1)
                 count++;
                 //Counts Number of 1s in binary representation
          }
          if( count % 2 == 0 )
               printf("Case %d: even\n",cn++);
          else
               printf("Case %d: odd\n",cn++);
     }

     return 0;
}
