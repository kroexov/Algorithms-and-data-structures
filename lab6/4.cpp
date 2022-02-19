#include <iostream>
#include <list>
#include <vector>
#include <utility>
 
using namespace std;
 
struct Element{
    string key;
    list<string>values[100];
};
list<Element> multimap [1000000];
 
long long int number(string key){
    int multiplier = 263;
    int prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = key.size() - 1; i >= 0; --i)
        hash = (hash * multiplier + key[i]) % prime;
    return hash %1000000;
}
 
long long int numby(string key){
    int multiplier = 10;
    int prime = 1000007;
    unsigned long long hash = 0;
    for (int i = key.size() - 1; i >= 0; --i)
        hash = (hash * multiplier + key[i]) % prime;
    return hash % 100;
}
 
void put(string x,string y) {
    long long int num = number(x);
    long long int numy = numby(y);
    for (list<Element>::iterator i = multimap[num].begin(); i != multimap[num].end(); i++) {
        if (i->key == x){
            for (list<string>::iterator j = i->values[numy].begin(); j != i->values[numy].end(); j++) {
                if (*j==y)
                    return;
            }
            i->values[numy].push_back(y);
            return;
        }
    }
    Element* newby= new Element;
    newby->key=x;
    newby->values[numy].push_back(y);
    multimap[num].push_back(*newby);
}
 
void delpair(string x,string y){
    long long int num = number(x);
    long long int numy = numby(y);
    for (list<Element>::iterator i = multimap[num].begin(); i != multimap[num].end(); i++) {
        if (i->key == x) {
            for (list<string>::iterator j = i->values[numy].begin(); j != i->values[numy].end(); j++) {
                if (*j == y) {
                    i->values[numy].erase(j);
                    return;
                }
            }
        }
    }
}
 
void delall(string x){
    long long int num = number(x);
    for (list<Element>::iterator i = multimap[num].begin(); i != multimap[num].end(); i++) {
        if (i->key == x) {
            multimap[num].erase(i);
            return;
        }
    }
}
 
pair<int, vector<string>> get(string x){
    vector<string> answer;
    long long int num = number(x);
    if (multimap[num].empty()){
        return make_pair(0, answer);
    }
    int summ=0;
    for (list<Element>::iterator i = multimap[num].begin(); i != multimap[num].end(); i++) {
        if (i->key == x) {
            for (int j = 0; j < 100; j++) {
                summ+=i->values[j].size();
            }
            for (int j=0; j<100; j++){
                for (list<string>::iterator k = i->values[j].begin(); k != i->values[j].end(); k++){
                    answer.push_back(*k);
                }
            }
        }
    }
    return make_pair(summ, answer);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
#endif
    string command;
    string x1;
    string x2;
    while (cin >> command) {
        if (command=="put"){
            cin >> x1 >> x2;
            put(x1,x2);
        }
        if (command=="get"){
            cin >> x1;
            pair<int, vector<string>> ans = get(x1);
            cout << ans.first << " ";
            for (int i = 0; i < ans.second.size(); i++) {
                cout << ans.second[i] << " ";
            }
            cout << '\n';
        }
        if (command=="delete"){
            cin >> x1 >> x2;
            delpair(x1,x2);
        }
        if (command=="deleteall"){
            cin >> x1;
            delall(x1);
        }
    }
    return 0;
}
