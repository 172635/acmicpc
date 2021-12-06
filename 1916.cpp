//11779
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int>> link[1001];
int cost[1001];
bool check[1001];

struct cmp{
    bool operator()(const int &a, const int &b){
        return cost[a]>cost[b];
    }
};

int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        link[a].emplace_back(b,c);
    }
    int s,e;
    scanf("%d %d",&s,&e);
    for(int i=1;i<=n;i++){
        cost[i] = -1;
    }
    priority_queue<int,vector<int>,cmp> q;
    q.push(s);
    cost[s] = 0;
    while(!q.empty()){
        int now = q.top();
        q.pop();
        if(check[now]==true){
            continue;
        }
        check[now] = true;
        for(int i=0;i<link[now].size();i++){
            int next = link[now][i].first;
            if(cost[next]>cost[now]+link[now][i].second||cost[next] == -1){
                cost[next] = cost[now]+link[now][i].second;
                q.push(next);
            }
        }
    }
    printf("%d",cost[e]);
    return 0;
}
