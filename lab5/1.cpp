#include <iostream>
#include <fstream>
using namespace std;
 
struct Node{
    int value;
    int left;
    int right;
};
Node Tree[2000001]={};
int max_height(int i){
    if (i==0)
        return 0;
    int right=Tree[i].right;
    int left=Tree[i].left;
    if (right==0 and left==0) {
        return 1;
    }
    return max(max_height(left),max_height(right))+1;
}
int main() {
    ifstream inp("height.in");
    ofstream out("height.out");
    int n;
    inp>>n;
    for(int i=1;i<n+1;i++){
    inp>>Tree[i].value>>Tree[i].left>>Tree[i].right;
    }
    int height;
    height=max_height(1);
    if (n==0)
        out<<0;
    else
        out<<height;
}
