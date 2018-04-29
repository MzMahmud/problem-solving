#include <bits/stdc++.h>
#define SIZE 1005

using namespace std;

bool isPrime[SIZE/2];
vector <int> nPrime;
int dist[SIZE+3];
vector<int>primeFactors[SIZE+3];
void primeSieve(int n)
{
    nPrime.push_back(2);

    int limit = sqrt(n+0.0) + 2;
    for(int i = 3;i <= n;i += 2){
        if( !isPrime[(i+1)/2] ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j += (i*2) ){
                    isPrime[(j+1)/2] = 1;
                }
            }
        }
    }
}
void primeFactorize(){
    for(int i = 2;i < SIZE;i++){
        for(int j = 0;j < nPrime.size();j++){
            if(nPrime[j] >= i) break;
            if(i%nPrime[j] == 0){
            	primeFactors[i].push_back(nPrime[j]);
            }
        }
    }
}


int bfs(int s,int t){
    memset(dist,-1,sizeof(dist));
    if(s > t) return -1;

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i = 0;i < primeFactors[a].size();i++){
            int next = a + primeFactors[a][i];
            if(dist[next] < 0 && next <= t){
                q.push(next);
                dist[next] = dist[a] + 1;
            }
        }
    }
    return dist[t];
}

int main(){
    //freopen("in.txt","r",stdin);
    primeSieve(SIZE);
    primeFactorize();

    int T,cn = 1;
    scanf("%d",&T);

    while(T--){
        int s,t;
        scanf("%d%d", &s,&t);
        printf("Case %d: %d\n",cn++,bfs(s,t));
    }
    return 0;
}
