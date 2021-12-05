//11279 - array
#include <cstdio>
#include <vector>
using namespace std;
int Data[100001];
int num = 0;

void push(int x){
    num ++;
    int k = num;
    while(k>1){
        if(Data[k/2]<x){
            Data[k] = Data[k/2];
            k = k/2;
        }else{
            break;
        }
    }
    Data[k] = x;
}
int pop(){
    if(num==0){
        return 0;
    }
    int result = Data[1];
    int k = 1;
    while(k<num){
        if(k*2+1<num){
            if(Data[k*2]<Data[k*2+1]){
                if(Data[k*2+1]>Data[num]){
                    Data[k] = Data[k*2+1];
                    k = k*2+1;
                }else{
                    break;
                }
            }else{
                if(Data[k*2]>Data[num]){
                    Data[k] = Data[k*2];
                    k = k*2;
                }else{
                    break;
                }
            }
        }else if(k*2<num){
            if(Data[k*2]>Data[num]){
                Data[k] = Data[k*2];
                k = k*2;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    Data[k] = Data[num];
    num --;
    return result;
}

int main(){
    int N;
    scanf("%d",&N);
    vector<int> result;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        if(x==0){
            result.push_back(pop());
        }else{
            push(x);
        }
    }
    for(int i=0;i<result.size();i++){
        printf("%d\n",result[i]);
    }
    return 0;
}
