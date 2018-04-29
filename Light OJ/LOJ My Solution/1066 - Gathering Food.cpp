/*
    //LOJ 1066 - Gathering Food
    Author : Moaz Mahmud
    Date   : 02 May,2017
    My Solution:
        The idea is to break the problem into steps. First look for
        Shortest Path between (A,B) then (B,C) then (C,D) ans so on.
        Now as for d(A,B) the only valid letter is B as the problem
        says in reaching a cell with letter it must be picked.
        And also when (A,B) is done its done then the cell with A can be visited.
        So its changed to '.' . Thats also true when looking for d(C,D),B is changed
        to '.' .
        In any step if a food can't be gathered then the task is impossible.
    END
*/

#include<cstdio>
#include<queue>
#define SIZE 15
#define inRange(x,y) ( x >= 0 && y >= 0 && x < n && y < n )
#define isLetter(f) (f >= 'A' && f <= 'Z')

using namespace std;

char MAT[SIZE][SIZE];
int dist[SIZE][SIZE];
pair<int,int> foods[26];
int n;

int bfs(pair<int,int> s,pair<int,int> d,char food){
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            dist[i][j] = -1;//works as visited array. its visited is dist[i][j] > 0

    dist[s.first][s.second] = 0;
    queue< pair<int,int> > q;
    q.push(s);

    while(!q.empty()){
        pair<int,int> u = q.front();q.pop();
        int x = u.first,y = u.second;

        //visits the adjacent nodes
        //down node
        if(inRange(x+1,y) && MAT[x+1][y] != '#' && dist[x+1][y] < 0/*this means if its not visited yet*/){
            if(isLetter(MAT[x+1][y])){//if its letter
                if(MAT[x+1][y] == food)//and is the proper food then in other wise not
                    return dist[x][y] + 1;//as destination is reached d(s,d) is returned
            }
            else{
                q.push(make_pair(x+1,y));
                dist[x+1][y] = dist[x][y] + 1;
            }
        }
        //up node
        if(inRange(x-1,y) && MAT[x-1][y] != '#' && dist[x-1][y] < 0){
            if(isLetter(MAT[x-1][y])){
                if(MAT[x-1][y] == food)
                    return dist[x][y] + 1;
            }
            else{
                q.push(make_pair(x-1,y));
                dist[x-1][y] = dist[x][y] + 1;
            }
        }
        //right node
        if(inRange(x,y+1) && MAT[x][y+1] != '#' && dist[x][y+1] < 0){
            if(isLetter(MAT[x][y+1])){
                if(MAT[x][y+1] == food)
                    return dist[x][y] + 1;
            }
            else{
                q.push(make_pair(x,y+1));
                dist[x][y+1] = dist[x][y] + 1;
            }
        }
        //left node
        if(inRange(x,y-1) && MAT[x][y-1] != '#' && MAT[x][y-1] != 'm' && dist[x][y-1] < 0){
            if(isLetter(MAT[x][y-1])){
                if(MAT[x][y-1] == food)
                    return dist[x][y] + 1;
            }
            else{
                q.push(make_pair(x,y-1));
                dist[x][y-1] = dist[x][y] + 1;
            }
        }
    }
    return dist[d.first][d.second];
    //if reachable the value is already returned.
    //if not here a negative value is returned here.
}

int main(){
    freopen("in.txt","r",stdin);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int ans = 0;
        scanf("%d", &n);
        for(int i = 0;i < n;i++) scanf("%s",MAT[i]);

        int totalFoods = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isLetter(MAT[i][j])){
                    foods[MAT[i][j] - 'A'] = make_pair(i,j);//stores the position of the foods
                    totalFoods++;//total number of foods
                }
            }
        }

        bool impossible = false;
        for(int i = 0;i < totalFoods - 1 ;i++){
            MAT[foods[i].first][foods[i].second] = '.';
            //makes the source accessible for the next iteration.

            int a = bfs(foods[i],foods[i+1],'A' + i + 1);
            if(a < 0){impossible = true;break;}//if negative its current target food is not gathered
            ans += a;
        }
        printf("Case %d: ",cn++);
        if(impossible) printf("Impossible\n");
        else           printf("%d\n",ans);
    }
    return 0;
}
