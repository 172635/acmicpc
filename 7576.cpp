#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ToIn[1001][1001]; //tomato_info
int Day[1001][1001];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int y=1;y<=m;y++){
        for(int x=1;x<=n;x++){
            int a;
            scanf("%d",&a);
            ToIn[x][y] = a;
        }
    }
    queue<pair<int,int>> tile_now;
    for(int y=1;y<=m;y++){
        for(int x=1;x<=n;x++){
            if(ToIn[x][y]==1){
                tile_now.push(make_pair(x,y));
            }
        }
    }
        while(!tile_now.empty()){
        int now_x = tile_now.front().first;
        int now_y = tile_now.front().second;
        tile_now.pop();
        for(int d=0;d<4;d++){
            int next_x = now_x + dx[d];
            int next_y = now_y + dy[d];
            if(next_x>0&&next_x<n+1&&next_y>0&&next_y<m+1&&ToIn[next_x][next_y]==0){
                if(Day[next_x][next_y]==0||Day[next_x][next_y]>Day[now_x][now_y]+1){
                    Day[next_x][next_y] = Day[now_x][now_y]+1;
                    tile_now.push(make_pair(next_x,next_y));
                }
            }
        }
    }
    int max_day = 0;
    int check_none = 0;
    for(int x=1;x<=n;x++){
        if(check_none==1){
            break;
        }
        for(int y=1;y<=m;y++){
            if(Day[x][y]>max_day){
                max_day = Day[x][y];
            }else if(Day[x][y] == 0&&ToIn[x][y]==0){
                max_day = -1;
                check_none = 1;
                break;
            }
        }
    }
    printf("%d",max_day);
    return 0;
}
