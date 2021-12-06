//2606
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> link[101];
bool check[101];

int main(){
    int N;
    scanf("%d",&N);
    int E;
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    check[1] = true;
    int num = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<link[now].size();i++){
            if(check[link[now][i]]==false){
                check[link[now][i]] = true;
                q.push(link[now][i]);
                num ++;
            }
        }
    }
    printf("%d",num);
}
