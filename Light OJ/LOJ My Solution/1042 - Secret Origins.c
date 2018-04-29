#include <stdio.h>
#define testBit(n,b) ( (n & 1 << b) == 0? 0 : 1 )
#define resetBit(n,b)( n & (~(1 << b)) )
#define setBit(n,b)  ( n | (1 << b) )

int justLarger(int n);

int main()
{
    int T,cn = 1;
    int n;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("Case %d: %d\n", cn++,justLarger(n));
    }
    return 0;
}

int justLarger(int n)
{
    short int one = 0,zero = 0,i,index,j;

    for(i = 0;i < 32;i++){
        if( testBit(n,i) )
             one++;
        else zero++;

        if( testBit(n,i) && !(testBit(n,i+1))){
            index = i;
            one--;
            n = resetBit(n,i);
            n = setBit(n,i+1);
            break;
        }
    }
    for( j = index,i = 1; i <= zero;i++ ){
        j = index - i;
        n = resetBit( n,j );
    }
    index = j;
    for( j = index,i = 1; i <= one;i++ ){
        j = index - i;
        n = setBit( n,j );
    }
    return n;
}
