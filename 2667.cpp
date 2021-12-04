#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map_[25][25];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


int main(){
    int N;
    scanf("%d",&N);
    int num = 0;
    vector<int> result;
    for(int i=0;i<N;i++){
        char line[25];
        scanf("%s",line);
        for(int j=0;j<N;j++){
            map_[i][j] = line[j] - 48;
        }
    }
    queue<pair<int,int>> s;
    int sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            num = 0;
            if(map_[i][j]==1){
                s.push(make_pair(i,j));
                map_[i][j]=0;
                num ++;
                while(!s.empty()){
                    pair<int,int> n = s.front();
                    s.pop();
                    for(int k=0;k<4;k++){
                        if(n.first+dx[k]<0||n.first+dx[k]>=N||n.second+dy[k]<0||n.second+dy[k]>=N){
                            continue;
                        }
                        if(map_[n.first+dx[k]][n.second+dy[k]]!=0){
                            map_[n.first+dx[k]][n.second+dy[k]] = 0;
                            s.push(make_pair(n.first+dx[k], n.second+dy[k]));
                            num ++;
                        }
                    }
                }
                result.push_back(num);
                sum ++;
            }
        }
    }
    printf("%d",sum);
    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++){
        printf("\n%d",result[i]);
    }
}
