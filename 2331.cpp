#include <cstdio>
#include <vector>

using namespace std;

bool check_list[10000];

int pow(int a, int n){
    if(n==1)
        return a;
    return pow(a,n-1)*a;
}
int calcu(int a, int n){
    if(a<10)
        return pow(a,n);
    return calcu(a/10,n)+pow(a%10,n);
}
int main(){
    vector<int> road;
    int start, n;
    scanf("%d %d",&start,&n);
    road.push_back(start);
    check_list[start] = true;
    int now, next;
    while(1){
        now = road.back();
        next = calcu(now, n);
        if(check_list[next]==true){
            for(int i=0;i<road.size();i++){
                if(road[i]==next){
                    printf("%d",i);
                }
            }
            break;
        }
        else{
            check_list[next]=true;
            road.push_back(next);
        }
    }
    return 0;
}
