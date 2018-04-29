/*
    //LOJ 1337 - The Crystal Maze.
    Author : Moaz Mahmud
    Date   : 02 May,2017
    My Solution:
        The idea is that, in any cell (x,y) the number of maximum crystal(#C)
        would be the same as its adjacent cell. Because if you can reach
        all possible #C in a run.
        Now my solution does it in a single DFS run.
        in every dfsVisit as the #C is fixed so a common pointer is stored
        in query[x][y] cell. Then if any C is found then value of the common pointer
        is increased. So when full dfs is complete query[x][y] contains the common
        pointer. So the answer is the value if query[x][y] pointer.
    END
*/
#include<cstdio>
#include<iostream>
#define SIZE 500
#define inRange(x,y) ( x >= 0 && y >= 0 && x < m && y < n )

using namespace std;

char MAT[SIZE][SIZE];//the maze matrix
bool visited[SIZE][SIZE];//visited array
int* query[SIZE][SIZE];//the query array to store pointer of the answer
int* ans[SIZE*SIZE];//the answer pointers. Maximum size SIZE^2.
int m,n;//boundary

void dfsVisit(int x,int y,int* a){
    if(!inRange(x,y) || visited[x][y] || MAT[x][y] == '#') return;

    visited[x][y] = true;
    query[x][y] = a;//the common pointer is stored in query[x][y].
    if(MAT[x][y] == 'C') (*a)++;//if crystal is found then the common answer is increased

    //visits to its adjacent nodes
    dfsVisit(x+1,y,a);//down node
    dfsVisit(x-1,y,a);//up node
    dfsVisit(x,y+1,a);//right node
    dfsVisit(x,y-1,a);//left node
}

void dfs(){
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            visited[i][j] = false;

    int k = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(!visited[i][j]){
                int* p = ans[k];//the common pointer
                *p = 0;//the value is initialized by 0;
                k++;//ready for next common pointer
                dfsVisit(i,j,p);
            }
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    for(int i = 0;i < SIZE*SIZE;i++)//allocating memory for the common answer pointers
        ans[i] = new int[1];

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int q,x,y;

        //Input
        scanf("%d%d%d", &m,&n,&q);
        for(int i = 0;i < m;i++) scanf("%s",&MAT[i]);

        //generating ans
        dfs();
        printf("Case %d:\n",cn++);
        for(int i = 0;i < q;i++){
            scanf("%d%d", &x,&y);
            printf("%d\n",*query[x-1][y-1]);
            //for each query the answer is the value at the
            //pointer stored in query[x-1][y-1]
            //[x-1][y-1] because their indexing starts with 1 mine 0.
        }
    }
    return 0;
}
