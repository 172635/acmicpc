//1927 - priority
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        if(x==0){
            if(q.empty()){
                printf("0\n");
            }else{
                printf("%d\n",q.top());
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
    return 0;
}
