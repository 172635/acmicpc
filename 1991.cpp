#include <iostream>
using namespace std;
int a[50][2];
void preorder(int x){
    printf("%c",x+65);
    if(a[x][0]>=0)
        preorder(a[x][0]);
    if(a[x][1]>=0)
        preorder(a[x][1]);
}
void inorder(int x){
    if(a[x][0]>=0)
        inorder(a[x][0]);
    printf("%c",x+65);
    if(a[x][1]>=0)
        inorder(a[x][1]);
}
void postorder(int x){
    if(a[x][0]>=0)
        postorder(a[x][0]);
    if(a[x][1]>=0)
        postorder(a[x][1]);
    printf("%c",x+65);
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        char x,y,z;
        cin >> x >> y >> z;
        x = x-'A';
        y = y-'A';
        z = z-'A';
        a[x][0] = y;
        a[x][1] = z;
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}
