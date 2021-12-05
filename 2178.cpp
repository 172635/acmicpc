//2178
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int maze[100][100];
int LenM[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        char line[101];
        scanf("%s",line);
        for(int j=0;j<M;j++){
            maze[i][j] = line[j] - 48;
        }
    }
    queue<pair<int,int>> mazeS;
    LenM[0][0] = 1;
    mazeS.push(make_pair(0,0));
    while(!mazeS.empty()){
        pair<int,int> now = mazeS.front();
        if(now.first == N-1&&now.second == M-1){
            break;
        }
        mazeS.pop();
        for(int k=0;k<4;k++){
            int nextY = now.first+dy[k];
            int nextX = now.second+dx[k];
            if(nextX<0||nextY<0||nextX>=M||nextY>=N){
                continue;
            }
            if(maze[nextY][nextX] == 1 && LenM[nextY][nextX]==0){
                LenM[nextY][nextX] = LenM[now.first][now.second]+1;
                mazeS.push(make_pair(nextY,nextX));
            }
        }
    }
    printf("%d",LenM[N-1][M-1]);
}
