#include <stdio.h>
#include <string.h>

struct month{
    char name[15];
};
struct month all[12] = {"January","February","March","April",
       "May","June","July","August","September",
       "October","November","December"};

int main()
{
    freopen("Input.txt","rt",stdin);
    int tc,cn = 1,d1,d2,m1,m2,y1,y2,i,ans;
    char month1[15],month2[15];

    scanf("%d", &tc);
    while( tc-- ){
        scanf("%s%d,%d", month1,&d1,&y1);
        scanf("%s%d,%d", month2,&d2,&y2);

        for(i = 0;i < 12;i++){
            if( strcmp(month1,all[i].name) == 0)
                m1 = i;
            if( strcmp(month2,all[i].name) == 0)
                m2 = i;
            //Comparing with Dataset finds which month inputed
        }

        if( (m1 == 1 && d1 <= 29) || m1 < 1 )
             y1 = y1 - 1;
        /* In starting date if the Day,Month is before Feb,29
        then the year is counted.As there is chance of getting a Leap year Day */
        else y1 = y1;
        if( (m2 == 1 && d2 < 29) || m2 < 1 )
             y2 = y2 - 1;
        else y2 = y2;
        /* In finishing date if the Day,Month is after Feb,29
        then the year is counted.As there is chance of getting a Leap year Day */

        ans = ( (y2/4) - (y1/4) ) - ( (y2/100) - (y1/100) ) + ( (y2/400) - (y1/400) );
        /* Leap year is : 4|year and (if 100|year and 400|year as well)
        EX:Though 4|1700 , 100|1700 but 400 does not divide 1700.So not Leap Year
        so total = (#divisible of 4) - (#divisible of 100) + (#divisible of 400) [ # means Number of]
        #divisible of d from 1 to n is : floor(n/d)
        #divisible of d in [lo,up] is : (#divisible[1,up])-(#divisible[1,low-1])
        Already determined the lo year in if section */
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
