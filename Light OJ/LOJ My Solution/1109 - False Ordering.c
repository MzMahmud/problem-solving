#include <stdio.h>
#include <math.h>

int main()
{
    int tc,cn=1,n,i,j,k;
    int num[1001],NOD[1001];

    for(i=1;i<1001;i++){
        NOD[i] = nod(i);
        num[i] = i;
    }

    for(i=1;i<1001;i++){
        for(j=2;j<1001;j++){
            if(NOD[j]<NOD[j-1]){
                n = num[j-1],k = NOD[j-1];
                num[j-1] = num[j],NOD[j-1] = NOD[j];
                num[j] = n,NOD[j] = k;
            }
            if(NOD[j] == NOD[j-1]){
                if(num[j]>num[j-1]){
                    n = num[j-1],k = NOD[j-1];
                    num[j-1] = num[j],NOD[j-1] = NOD[j];
                    num[j] = n,NOD[j] = k;
                }
            }
        }
    }

    scanf("%d",&tc);
    while( tc-- ){
        scanf("%d",&n);
        printf("Case %d: %d\n",cn++,num[n]);
    }
    return 0;
}

int nod(int n)
{
    int count = 0,i;
    if(n==1)
        return 1;
    for(i=1;i<=(int)sqrt(n);i++){
        if(n%i==0)
            count++;
    }
    count *= 2;
    if( (double)sqrt(n) == (int)sqrt(n) )
        count--;

    return count;
}
