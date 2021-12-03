#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

bool link[1001][1001];
bool check[1001];
int N, M, V;

int main(){
    int a,b,node;
    scanf("%d %d %d",&N, &M, &V);
    for(int i=0;i<M;i++){
        scanf("%d %d",&a, &b);
        link[a][b] = true;
        link[b][a] = true;
    }
    stack<int> dfs;
    dfs.push(V);
    while(!dfs.empty()){
        node = dfs.top();
        dfs.pop();
        if(check[node]==true)
            continue;
        check[node]=true;
        printf("%d ",node);
        for(int i=N;i>=1;i--){
            if(link[node][i]==true){
                dfs.push(i);
            }
        }
    }
    memset(check,false,sizeof(check));
    printf("\n");
    queue<int> bfs;
    bfs.push(V);
    while(!bfs.empty()){
        node = bfs.front();
        bfs.pop();
        if(check[node]==true)
            continue;
        check[node]=true;
        printf("%d ",node);
        for(int i=1;i<=N;i++){
            if(link[node][i]==true){
                bfs.push(i);
            }
        }
    }
    return 0;
}
