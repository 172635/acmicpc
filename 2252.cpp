//2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32001

vector<int> st[MAX];
int st_num[MAX];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        st[a].push_back(b);
        st_num[b] += 1;
    }
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(st_num[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d ",now);
        for(int i=0;i<st[now].size();i++){
            int next = st[now][i];
            st_num[next] -= 1;
            if(st_num[next]==0){
                q.push(next);
            }
        }
    }
    return 0;
}
