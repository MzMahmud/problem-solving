#include <stdio.h>
#include <string.h>

char a1[103],b1[103];
void store(char [],char []);
void sort(char []);

int main()
{
    int tc,cn = 1;
    char a[103],b[103];

    scanf("%d\n",&tc);
    while(tc--){
        gets(a);
        gets(b);
        store(a,b);
        sort(a1);
        sort(b1);

        printf("Case %d: ",cn++);
        if( strcmp(a1,b1) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

void store(char a[],char b[])
{
    int i,j;

    for(i=0,j=0;i < strlen(a);i++){
        if(a[i] !=' '){
            if(a[i]>='A' && a[i]<='Z')
                a[i] = 'a' + (a[i] - 'A');
            a1[j++] = a[i];
        }
    }
    a1[j] = '\0';

    for(i=0,j=0;i < strlen(b);i++){
        if(b[i] != ' '){
            if(b[i]>='A' && b[i]<='Z')
                b[i] = 'a' + (b[i] - 'A');
            b1[j++] = b[i];
        }
    }
    b1[j] = '\0';
}

void sort(char a[])
{
    int i,j;
    char t;
    for(i = 0;i<strlen(a);i++){
        for(j = 1;j<strlen(a);j++){
            if(a[j] < a[j-1]){
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
    }
}
