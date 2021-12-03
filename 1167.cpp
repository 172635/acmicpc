#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int,int>> arrow[100001];
bool check[100001];
int max_distance;
int max_num;
int start;

void dfs(int n, int dist){
    check[n] = true;
    if(dist>max_distance){
        max_distance = dist;
        max_num = n;
    }
    for(int i=0;i<arrow[n].size();i++){
        int k1 = arrow[n][i].first;
        int k2 = arrow[n][i].second;
        if(check[k1]==true)
            continue;
        dfs(k1, k2 + dist);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int n;
        scanf("%d",&n);
        int k1, k2;
        scanf("%d",&k1);
        while(k1!=-1){
            scanf("%d",&k2);
            arrow[n].emplace_back(k1,k2);
            scanf("%d",&k1);
        }
    }
    start = 1;
    dfs(1, 0);
    max_distance = 0;
    memset(check, false, sizeof(check));
    start = max_num;
    dfs(max_num, 0);
    printf("%d",max_distance);
    return 0;
}