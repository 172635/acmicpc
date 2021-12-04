#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int check[20001];
int main(){
    int N;
    scanf("%d",&N);
    string final = "";
    for(int i=0;i<N;i++){
        int V, E;
        scanf("%d %d",&V,&E);
        vector<int> link[20001];
        for(int j=0;j<E;j++){
            int u, v;
            scanf("%d %d",&u,&v);
            link[u].push_back(v);
            link[v].push_back(u);
        }
        queue<int> Bgraph;
        string answer = "YES";
        for(int k=1;k<=V;k++){
            if(check[k]==0){
                check[k]=1;
                Bgraph.push(k);
                while(!Bgraph.empty()){
                    int now = Bgraph.front();
                    Bgraph.pop();
                    for(int n=0;n<link[now].size();n++){
                        if(check[link[now][n]]==0){
                            check[link[now][n]]=3-check[now];
                            Bgraph.push(link[now][n]);
                        }else if(check[link[now][n]]==check[now]){
                            answer = "NO";
                        }
                    }
                }
            }
            check[k]=0;
        }
        final += answer;
        if(i!=(N-1)){
            final += "\n";
        }
    }
    cout << final;
    return 0;
}
