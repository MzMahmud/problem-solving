/*
    LOJ 1292 - Laser Shot
    Author: Moaz Mahmud
    Date  : 28 Oct,2017

    My Solution:
        if a line starts from A and covers some points B,C,D then
        slope of AB,AC,AD would be same.
        as slope = dell y/dell x its necessary to keep unique pairs
        of (dell x,dell y) making sure its reduced and negative sigh
        assigned to a specific one. Then just count the overlap of slopes
        for all pairs.The answer would be the maximum one among all.
        Complexity: for all points O(nlgn).Over all O(n^2lgn)
    END :D :D
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define ABS(x) (x < 0?-x:x)

using namespace std;

struct point{
    int x,y;
    point(int _x = 0,int _y = 0){this->x = _x;this->y = _y;}
    bool  operator==(point a){ return (this->x == a.x) && (this->y == a.y); }
};
bool operator<(point a,point b){return (a.x == b.x)? (a.y < b.y) : (a.x < b.x);}//needed for sort()

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        vector<point> points;
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d", &x,&y);
            points.push_back(point(x,y));
        }
        int maxN = 1;//1,because at least 1 point aligns
        for(int i = 0;i < points.size()-1;i++){
            vector<point> slopes;
            for(int j = i+1;j < points.size();j++){
                int x,y;
                x  = points[i].x - points[j].x;
                y  = points[i].y - points[j].y;
                int g = __gcd(ABS(x),ABS(y));
                if(g){x /= g;y/=g;}//reduced
                if(x >= 0 && y <= 0 || x <= 0 && y <= 0){x = -x,y = -y;}
                //negative sigh is always in x.
                slopes.push_back(point(x,y));
            }
            sort(slopes.begin(),slopes.end());//sorted to count same slopes
            int k = 0,match;
            while(k < slopes.size()){
                int l = k;
                match = 1;//1,because at least 1 point aligns(to itself)
                while(slopes[k] == slopes[l]){match++;l++;}
                if(match > maxN) maxN = match;
                k = l;
            }
        }
        printf("Case %d: %d\n",cn++,maxN);
    }
    return 0;
}
