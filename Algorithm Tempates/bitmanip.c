#include <stdio.h>
#define CHECK(n,p) ( n &   (1<<p) )
#define   SET(n,p) ( n |=  (1<<p) )
#define RESET(n,p) ( n &= ~(1<<p) )
#define  FLIP(n,p) ( n ^=  (1<<p) )
#define  SHOW(n)   {int i;for(i = 8*sizeof(n)-1;i >= 0;i--){printf("%c",CHECK(n,i)?'1':'0');if(!(i&3))printf(" ");}printf("\n");}
int main(){
    int a = 0xFF;
    for(a = 0;a < 32;a++){
        printf("%5d -> ", (int)a);
        SHOW(a);
    }
    return 0;
}
