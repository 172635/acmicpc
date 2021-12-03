#include <cstdio>
#include <cstring>

int link[1001];
bool check[1001];
int main(){
    int N;
    scanf("%d",&N);
    for(int N_i=0;N_i<N;N_i++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            link[i]=a;
        }
        int num = 0;
        memset(check, false, sizeof(check));
        for(int i=1;i<=n;i++){
            if(check[i]==false){
                num++;
                int next = link[i];
                check[i] = true;
                while(check[next]==false){
                    check[next]=true;
                    next = link[next];
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}