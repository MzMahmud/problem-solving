#include<stdio.h>

int a[500002];

void mSort(int f, int l)
{
    int ara[500002], i, j, k, m;

    if(f == l)
        return;

    m = f + (l - f) / 2;
    mSort(f, m);
    mSort(m+1, l);

    i = f;
    j = m+1;

    for(k = 0; k <= l - f; k++){
        if(i > m){
            ara[k] = a[j];
            j++;
        }

        else if(j > l){
            ara[k] = a[i];
            i++;
        }

        else if(a[i] < a[j]){
            ara[k] = a[i];
            i++;
        }

        else {
            ara[k] = a[j];
            j++;
        }
    }

    for(k = 0, i = f; k <= l - f; k++, i++ ){
        a[i] = ara[k];
    }
}

int main()
{
    int n, i, temp;
    long long int k;
    scanf("%d%I64d", &n, &k);

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    mSort(0,n-1);

    while(k--){
        if(a[0] < a[n-1]){
            a[0]++;
            a[n-1]--;
            temp = a[0];
            for(i = 1; i < n; i++){
                if(a[i] < temp){
                    a[0] = a[i];
                    a[i] = temp;
                    break;
                }
            }
            temp = a[n-1];
            for(i = n-2; i >= 0; i--){
                if(a[i] > temp){
                    a[n-1] = a[i];
                    a[i] = temp;
                    break;
                }
            }
        }
        else
            break;
    }

    printf("%d", a[n-1]-a[0]);

    return 0;
}