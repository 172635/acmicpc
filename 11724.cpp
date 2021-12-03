//น้มุ 11724
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

vector<int> link[1001];
int check[1001];
int num=0;
stack<int> mem;

int main(){
    int N, M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        if(check[i]==0){
            num++;
            mem.push(i);
            check[i]=num;
            while(!mem.empty()){
                int now = mem.top();
                mem.pop();
                for(int j=0;j<link[now].size();j++){
                    if(check[link[now][j]]!=num){
                        mem.push(link[now][j]);
                        check[link[now][j]] = num;
                    }
                }
            }
        }
    }
    printf("%d",num);
}
