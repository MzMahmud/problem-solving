#include <stdio.h>

int main() {
     int tc,cn = 1,n,win;
     char a[6];

     scanf("%d", &tc);
     while( tc-- ){
          scanf("%d%s", &n,a);
          if( a[0] == 'A' ){
               if(n%3 == 1)
                    win = 2;
               else
                    win = 1;
           }
           else{
               if(n%3 == 0)
                    win = 1;
               else
                    win = 2;
          }
          if(win == 1)
               printf("Case %d: Alice\n",cn++);
         else
               printf("Case %d: Bob\n");
    }
    return 0;
}
