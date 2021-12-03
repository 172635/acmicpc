#include <cstdio>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> preorder;
int N;
int count;
vector<int>::iterator iter;

void preord(int n){
    if(n == 0)
        return;
    if(n == 1){
        preorder.push_back(inorder[0]);
        iter = inorder.begin();
        inorder.erase(iter);
        iter = postorder.begin();
        postorder.erase(iter);
        return;
    }
    int mid = postorder[n-1];
    int mid_x;
    for(int i=0;i<n;i++){
        if(inorder[i]==mid){
            mid_x = i;
            break;
        }
    }
    preorder.push_back(mid);
    iter = inorder.begin();
    inorder.erase(iter+mid_x);
    iter = postorder.begin();
    postorder.erase(iter+n-1);
    preord(mid_x);
    preord(n-mid_x-1);
}

int main(){


    int temp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        inorder.push_back(temp);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        postorder.push_back(temp);
    }
    preord(N);

    for(int i=0;i<N;i++){
        printf("%d ",preorder[i]);
    }
}
