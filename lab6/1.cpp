#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
 
using namespace std;
ifstream inp("set.in");
ofstream out("set.out");
 
 
int number(long int x){
    double constanta=(sqrt(5)-1)/2;
    double useless;
    double result = modf(constanta*x,&useless);
    modf(255*result,&useless);
    return abs(int(useless));
}
void insert (long int x, vector<int> *hash){
    int num=number(x);
    for (int i = 0; i < int(hash[num].size()); i++) {
        if (hash[num][i] == x) {
            return;
        }
    }
    hash[num].push_back(x);
}
void exists (long int x, vector<int> *hash){
    int num=number(x);
    for (int i = 0; i < int(hash[num].size()); i++)
        if (hash[num][i] == x) {
            out << "true"<<endl;
            return;
        }
    out << "false"<<endl;
 
}
void del (long int x, vector<int> *hash){
    int num=number(x);
    for (int i = 0; i < int(hash[num].size()); i++) {
        if (hash[num][i] == x) {
            hash[num].erase(hash[num].begin() + i);
            break;
        }
    }
}
int main() {
    vector <int> hash[255];
    while (!inp.eof()) {
        string command;
        inp >> command;
        if (command == "insert"){
            int x;
            inp>>x;
            insert(x,hash);
        }
        if (command == "delete"){
            int x;
            inp>>x;
            del(x,hash);
        }
        if (command == "exists") {
            int x;
            inp >> x;
            exists(x,hash);
        }
    }
 
    return 0;
}
