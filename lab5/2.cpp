#include <iostream>
#include <fstream>
using namespace std;
ifstream inp("check.in");
ofstream out("check.out");
bool heap=true;
struct Node{
    int value;
    int left;
    int right;
    int max;
    int min;
};
Node Tree[2000001]={};
int minval(int cur){
    int left=Tree[cur].left;
    int right=Tree[cur].right;
    if (left==0 and right==0){
        Tree[cur].min=Tree[cur].value;
        return Tree[cur].value;
    }
    if (left==0 and right!=0) {
        Tree[cur].min=minval(right);
    }
    if (left!=0 and right==0) {
        Tree[cur].min=minval(left);
    }
    if (left!=0 and right!=0){
        Tree[cur].min=min(minval(right),minval(left));
    }
    return Tree[cur].min;
}
int maxval(int cur){
    int left=Tree[cur].left;
    int right=Tree[cur].right;
    if (left==0 and right==0){
        Tree[cur].max=Tree[cur].value;
        return Tree[cur].value;
    }
    if (left==0 and right!=0) {
        Tree[cur].max=maxval(right);
    }
    if (left!=0 and right==0) {
        Tree[cur].max=maxval(left);
    }
    if (left!=0 and right!=0){
        Tree[cur].max=max(maxval(right),maxval(left));
    }
    return Tree[cur].max;
}
void isheap(int cur){
    int left=Tree[cur].left;
    int right=Tree[cur].right;
    if (left==0 and right==0){
        return;
    }
    if ((left==0 or Tree[left].max<Tree[cur].value) and (right==0 or Tree[right].min>Tree[cur].value)) {
        if (left!=0)
            isheap(left);
        if (right!=0)
            isheap(right);
    }
    else{
        heap=false;
        return;
    }
}
int main() {
    int n;
    inp>>n;
    for(int i=1;i<n+1;i++){
        inp>>Tree[i].value>>Tree[i].left>>Tree[i].right;
    }
    minval(1);
    maxval(1);
    isheap(1);
    if (heap or n==0)
        out<<"YES";
    else
        out<<"NO";
 
}
