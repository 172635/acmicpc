//1717
#include <cstdio>

#define MAX 1000001

int parent[MAX];
int Find(int x){
    if(x==parent[x]){
        return x;
    }else{
        return parent[x] = Find(parent[x]);
    }
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}


int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==0){
            Union(b,c);
        }else{
            printf("%s\n",(Find(b)==Find(c)?"YES":"NO"));
        }
    }
    return 0;
}
