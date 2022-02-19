#include <iostream>
#include <fstream>
 
using namespace std;
 
struct Node {
    int key;
    int left, right;
    int height = -1;
};
 
int Treeheight(Node tree[], int cur) {
    if (tree[cur].height != -1)
        return tree[cur].height;
    if (cur == 0)
        return 0;
 
    int left = tree[cur].left;
    int right = tree[cur].right;
 
    tree[cur].height = max(Treeheight(tree, left), Treeheight(tree, right)) + 1;
    return tree[cur].height;
}
 
int main() {
    ifstream in("balance.in");
    ofstream out("balance.out");
    int n;
    in >> n;
    Node *Tree = new Node[n + 1];
    for (int i = 1; i <= n; i++)
        in >> Tree[i].key >> Tree[i].left >> Tree[i].right;
 
 
    for (int i = 1; i <= n; i++) {
        out << Treeheight(Tree, Tree[i].right) - Treeheight(Tree, Tree[i].left) << endl;
    }
 
    in.close();
    out.close();
    return 0;
}
