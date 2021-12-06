//2056 - 범용성 낮춤(문제 전용)
#include <cstdio>

int workTimeSum[10001];
int maxTimeSum;

int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int wt, n;
        scanf("%d %d",&wt,&n);
        for(int j=0;j<n;j++){
            int k;
            scanf("%d",&k);
            if(workTimeSum[i] < workTimeSum[k]){
                workTimeSum[i] = workTimeSum[k];
            }
        }
        workTimeSum[i] += wt;
        if(maxTimeSum<workTimeSum[i]){
            maxTimeSum = workTimeSum[i];
        }
    }
    printf("%d",maxTimeSum);
    return 0;
}
