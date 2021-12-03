#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int,int>> link[1001];
bool check[1001];
int main(){
    int N;
    scanf("%d",&N);
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        link[a].emplace_back(b,c);
        link[b].emplace_back(a,c);
    }
    check[1] = true;
    int lengthsum = 0;
    for(int i=0;i<N-1;i++){
        int length = 100001;
        int newn = 0;
        for(int n=1;n<=N;n++){
            if(check[n]==true){
                for(int k=0;k<link[n].size();k++){
                    if(length>link[n][k].second&&check[link[n][k].first]==false){
                        length = link[n][k].second;
                        newn = link[n][k].first;
                    }
                }
            }
        }
        check[newn] = true;
        lengthsum += length;
    }
    printf("%d",lengthsum);
}
