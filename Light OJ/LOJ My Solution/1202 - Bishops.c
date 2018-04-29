#include <stdio.h>
#define Abs(x) (x >= 0 ? x : (-1*x) )

int main() {
     int tc,cn=1,r1,c1,r2,c2,ans,d;

     scanf("%d", &tc);
     while( tc-- ){
          scanf("%d%d%d%", &r1,&c1,&r2,&c2);
          ans = -1;
          d = Abs( (r1 - r2) ) - Abs( (c1 - c2) );
          if( d == 0)
               ans = 1;
          else if( ( Abs(d)) % 2 == 0)
               ans = 2;
          if( ans != -1 )
               printf("Case %d: %d\n",cn++,ans);
          else
               printf("Case %d: impossible\n");
     }
     return 0;
}
