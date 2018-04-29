#include <stdio.h>

int count_zero(int );//Counts Zeros in n! .

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);

    int t,Case = 1,Z,i,d,k;

    scanf("%d", &t);
    while(t--){
        scanf("%d",&Z);
        k = 4*Z;
        //We know from Number Theory, any n! having Z zeros would be >= 4*Z
        d = -1;
        while(d < 0){
            i = count_zero(k);
            if(Z == i)
                d = k;

            else if(Z < i)
                d = 0;
            k++;
        }
        if(d == 0)
            printf("Case %d: impossible\n",Case++);
        else
            printf("Case %d: %d\n",Case++,d);
    }
    return 0;
}

int count_zero(int n)
{
    int zero = 0,k = 5;
    while(k <= n){
        zero = zero + (n/k);
        k = k*5;
    }
    return zero;
}

/*
//I solved this earlier.This time with Binary Search :)
#include <bits/stdc++.h>

using namespace std;

int zero(int n){
    int five = 1,Zero = 0;
    while(five <= n){
        five *= 5;
        Zero += (n/five);
    }
    return Zero;
}

int equals(int n){
    int z = zero(n);
    for(int i = n;;i--){
        if(zero(i) < z)
            return i+1;
    }
}

int main(){
    freopen("in.txt","r",stdin);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);

        int hi = 10*n,lo = 1,mid;

        while(hi > lo){
            mid = (hi+lo)/2;
                 if(zero(mid) == n)break;
            else if(zero(mid) > n) hi = mid - 1;
            else                   lo = mid + 1;
        }
        printf("Case %d: ",cn++);

        int z = zero(mid);
        if(z == n)
            printf("%d\n",equals(mid));
        else if(z > n){
            for(int i = mid;;i--){
                if(zero(i) == n){
                    printf("%d\n",equals(mid));
                    break;
                }else if(zero(i) < n){
                    printf("impossible\n");
                    break;
                }
            }
        }else{
            for(int i = mid;;i++){
                if(zero(i) == n){
                    printf("%d\n",equals(mid));
                    break;
                }else if(zero(i) > n){
                    printf("impossible\n");
                    break;
                }
            }
        }
    }
    return 0;
}
*/