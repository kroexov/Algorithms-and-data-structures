#include <iostream>
#include <string>
#include <vector>
#include <fstream>
 
using namespace std;
 
vector<int> prefix(string& s) {
    vector<int> p;
    p.resize(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int k = p[i - 1];
        while (k > 0 && s[i] != s[k])
            k = p[k - 1];
        if (s[i] == s[k])
            k++;
        p[i] = k;
    }
    return p;
}
 
int main() {
    ifstream in("prefix.in");
    ofstream out("prefix.out");
    string s;
    in >> s;
    vector<int> p = prefix(s);
    for (auto i : p) out << i << " ";
}
