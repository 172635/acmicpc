#include <cstdio>
#include <vector>

using namespace std;

vector<int> arrow[100001];
int parent[100001];

void find_parent(int n){
    for(int i=0;i<arrow[n].size();i++){
        int k = arrow[n][i];
        if(parent[k]!=0)
            continue;
        parent[k] = n;
        find_parent(k);
    }
}



int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        arrow[a].push_back(b);
        arrow[b].push_back(a);
    }
    find_parent(1);
    for(int i=2;i<=N;i++){
        printf("%d\n",parent[i]);
    }
    return 0;
}