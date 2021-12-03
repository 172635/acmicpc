#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int data_[101][101];
int island[101][101];
int bridge[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    int N;
    scanf("%d",&N);
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            scanf("%d",&data_[x][y]);
        }
    }
    int island_number = 1;
    queue<pair<int,int>> q;
    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            if(data_[x][y]==1&&island[x][y]==0){
                island[x][y] = island_number;
                q.push(make_pair(x,y));
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int i=0;i<4;i++){
                        int newX = p.first+dx[i];
                        int newY = p.second+dy[i];
                        if(data_[newX][newY]==1&&island[newX][newY]==0){
                            island[newX][newY] = island_number;
                            q.push(make_pair(newX,newY));
                        }
                    }
                }
                island_number ++;
            }
            bridge[x][y]=1000;
        }
    }
    int minBridge = 1000;
    for(int num = 1;num<island_number;num++){
        for(int x=1;x<=N;x++){
            for(int y=1;y<=N;y++){
                if(island[x][y]==num){
                    q.push(make_pair(x,y));
                    bridge[x][y]=0;
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        for(int i=0;i<4;i++){
                            int newX = p.first+dx[i];
                            int newY = p.second+dy[i];
                            if(data_[newX][newY]==0||island[newX][newY]!=num){
                                if(bridge[newX][newY]>bridge[p.first][p.second]+1){
                                    bridge[newX][newY] = bridge[p.first][p.second]+1;
                                    q.push(make_pair(newX,newY));
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int x=1;x<=N;x++){
            for(int y=1;y<=N;y++){
                int temp = bridge[x][y];
                bridge[x][y]=1000;
                if(island[x][y]!=0&&island[x][y]!=num){
                    if(temp==0){
                        continue;
                    }
                    if(minBridge>temp){
                        minBridge = temp;
                    }
                }
            }
        }
    }
    printf("%d",(minBridge-1));
    return 0;
}
