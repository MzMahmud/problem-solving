/*
    LOJ 1058 - Parallelogram Counting
    Author: Moaz Mahmud
    Date  : 27 Oct,2017

    My Solution:
        In a parallelogram ABCD mid point of AC,BD is same.
        So just sorted points to get all distinct pair of points
        and got all mid points.
        Sorted mid points and searched for matching.
        If one point matches k times,#parallelogram = C(k,2)

    END :D :D
*/

#include <bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
    point(int _x = 0,int _y = 0){this->x = _x;this->y = _y;}
    bool  operator==(point a){ return (this->x == a.x) && (this->y == a.y); }
    point operator+ (point a){ return point(this->x+a.x,this->y+a.y);}
};
bool operator<(point a,point b){return (a.x == b.x)? (a.y < b.y) : (a.x < b.x);}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        vector<point> a,mid;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a.push_back(point(x,y));
        }
        for(int i = 0;i < a.size()-1;i++)
            for(int j = i+1;j < a.size();j++)
                mid.push_back(a[i]+a[j]);

        sort(mid.begin(),mid.end());
        int i = 0;
        long long ans = 0;
        while(i < mid.size()){
            long long match = 0;
            int j = i;
            while(mid[i] == mid[j]){match++;j++;}
            ans += (match*(match-1))/2;//C(match,2)
            i = j;
        }
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
