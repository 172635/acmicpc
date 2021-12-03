#include <cstdio>
#include <vector>

using namespace std;

int pow(int a,int n){
    if(n==1){
        return a;
    }
    return a*pow(a,n-1);
}
int calcu(int A, int P){
    if(A<10){
        return pow(A,P);
    }
    return calcu(A/10,P)+pow(A%10,P);
}
bool check[1000001];
int main(){
    int sA, sP;
    scanf("%d %d",&sA,&sP);
    
    vector<int> list;
    list.push_back(sA);
    check[sA] = true;
    while(1){
        int now = calcu(list.back(),sP);
        if(check[now]==false){
            check[now]=true;
            list.push_back(now);
        }
        else{
            for(int i=0;i<list.size();i++){
                if(list[i]==now){
                    printf("%d",i);
                    break;
                }
            }
            break;
        }
    }
    return 0;
}