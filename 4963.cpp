//4963
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool Map[50][50];
int main(){
    vector<int> result;
    while(1){
        int w,h;
        scanf("%d %d",&w,&h);
        if(w==0&&h==0){
            break;
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int a;
                scanf("%d",&a);
                Map[i][j] = (a==1);
            }
        }
        queue<pair<int,int>> island;
        int island_num = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(Map[i][j]==true){
                    island_num ++;
                    island.push(make_pair(i,j));
                    Map[i][j] = false;
                    while(!island.empty()){
                        pair<int,int> now = island.front();
                        island.pop();
                        for(int k=0;k<8;k++){
                            if(now.first+dx[k]<0||now.second+dy[k]<0||now.first+dx[k]>=h||now.second+dy[k]>=w){
                                continue;
                            }
                            if(Map[now.first+dx[k]][now.second+dy[k]]==true){
                                island.push(make_pair(now.first+dx[k],now.second+dy[k]));
                                Map[now.first+dx[k]][now.second+dy[k]]=false;
                            }
                        }
                    }
                }
            }
        }
        result.push_back(island_num);
    }
    for(int i=0;i<result.size();i++){
        printf("%d\n",result[i]);
    }
    return 0;
}
