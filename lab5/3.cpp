#include <iostream>
#include <fstream>
 
using namespace std;
 
class Tree{
private:
    struct Node{
        int value;
        Node *parent;
        Node *left;
        Node *right;
    };
    Node head;
    int size = 0;
public:
    void insert(int x){
        if (size==0){
            head.value=x;
            head.parent=nullptr;
            head.left=nullptr;
            head.right=nullptr;
            size=1;
        }
        else{
            bool left=false;
            Node *cur = &head;
            Node *newby=new Node;
            newby->value=x;
            newby->left=nullptr;
            newby->right=nullptr;
            while (cur!=nullptr){
                newby->parent=cur;
                if (cur->value>x){
                    cur=cur->left;
                    left=true;
                }
                else if (cur->value<x){
                    cur=cur->right;
                    left=false;
                }
                else{
                    return;
                }
            }
            if (left)
                newby->parent->left=newby;
            else
                newby->parent->right=newby;
            size++;
        }
    }
    bool exist(int x) {
        if (size==0)
            return false;
        Node *cur = &head;
        while (cur!=nullptr) {
            if (cur->value>x)
                cur=cur->left;
            else if (cur->value<x)
                cur=cur->right;
            else
                return true;
        }
        return false;
    }
    int next(int x){
        if (size==0)
            return NULL;
        Node *cur = &head;
        while(true){
            if (cur->value<x and cur->right!=nullptr){
                cur = cur->right;
            }
            else if (cur->value>x and cur->left!=nullptr){
                cur = cur->left;
            }
            else {
                break;
            }
        }
        if (cur->value > x)
            return cur->value;
        if (cur->right!=nullptr) {
            Node *next;
            next = cur->right;
            while (next->left != nullptr)
                next = next->left;
            return next->value;
        }
        while (cur!=nullptr and cur->value<=x) {
            if (cur->parent == nullptr)
                return NULL;
            cur = cur->parent;
        }
        return cur->value;
    }
    int prev(int x){
        if (size==0)
            return NULL;
        Node *cur = &head;
        while(true){
            if (cur->value<x and cur->right!=nullptr){
                cur = cur->right;
            }
            else if (cur->value>x and cur->left!=nullptr){
                cur = cur->left;
            }
            else
                break;
        }
        if (cur->value < x)
            return cur->value;
        if (cur->left!=nullptr) {
            Node *prev;
            prev = cur->left;
            while (prev->right != nullptr)
                prev = prev->right;
            return prev->value;
        }
        while (cur!=nullptr and cur->value>=x){
            if (cur->parent == nullptr)
                return NULL;
            cur = cur->parent;
        }
        return cur->value;
    }
    void del(int x){
        if (size==0)
            return;
        Node *cur = &head;
        bool left=true;
        while (cur != nullptr) {
            if (cur->value < x) {
                cur = cur->right;
                left=false;
            } else if (cur->value > x) {
                cur = cur->left;
                left=true;
            }
            else
                break;
        }
        if (cur == nullptr)
            return;
        else {
            size--;
        }
        if (cur->left==nullptr && cur->right==nullptr) {
            if (cur->parent==nullptr){
                return;
            }
            else if (left)
                cur->parent->left=nullptr;
            else
                cur->parent->right=nullptr;
 
        }
        else if (cur->left==nullptr){
            if (cur->parent==nullptr) {
                cur->right->parent=nullptr;
                head = *(cur->right);
            }
            else {
                if (left)
                    cur->parent->left = cur->right;
                else
                    cur->parent->right = cur->right;
                cur->right->parent=cur->parent;
            }
        }
        else if (cur->right==nullptr){
            if (cur->parent==nullptr) {
                cur->left->parent=nullptr;
                head = *(cur->left);
            }
            else {
                if (left)
                    cur->parent->left = cur->left;
                else
                    cur->parent->right = cur->left;
                cur->left->parent=cur->parent;
            }
        }
        else{
            Node *deleted;
            deleted=cur->right;
            while(deleted->left!=nullptr)
                deleted=deleted->left;
            cur->value = deleted->value;
            if (deleted->parent->left == deleted)
                deleted->parent->left=deleted->right;
            else
                deleted->parent->right=deleted->right;
        }
    }
 
};
 
int main() {
    ifstream inp("bstsimple.in");
    ofstream out("bstsimple.out");
    Tree tree;
    while (!inp.eof()) {
        string command;
        inp >> command;
        if (command == "insert"){
            int x;
            inp>>x;
            tree.insert(x);
        }
        if (command == "delete"){
            int x;
            inp>>x;
            tree.del(x);
        }
        if (command == "exists"){
            int x;
            inp>>x;
            bool a=tree.exist(x);
            if (a)
                out<<"true"<<endl;
            else
                out<<"false"<<endl;
        }
        if (command == "next"){
            int x;
            inp>>x;
            if (tree.next(x)==NULL)
                out<<"none"<<endl;
            else
                out<<tree.next(x)<<endl;
        }
        if (command == "prev"){
            int x;
            inp>>x;
            if (tree.prev(x)==NULL)
                out<<"none"<<endl;
            else
                out<<tree.prev(x)<<endl;
        }
    }
    return 0;
}
