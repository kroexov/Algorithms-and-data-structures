#include <iostream>
#include <fstream>
#include <vector>
#include<math.h>
#include <utility>
 
using namespace std;
ifstream inp("map.in");
ofstream out("map.out");
 
long long int number(string key){
    long long int summ=0;
    long long int power=7;
    for (int i=0;i<key.size();i++){
        summ+=key[i]*power;
        power=power*5;
    }
    return summ%150000;
}
 
void put(string key, string val,  vector<pair<string,string>> *map){
    long long int num=number(key);
    for (int i=0;i<map[num].size();i++){
        if (map[num][i].first==key) {
            map[num][i].second = val;
            return;
        }
    }
    map[num].push_back(make_pair(key,val));
}
void get(string key,  vector<pair<string,string>> *map){
    long long int num=number(key);
    if (map[num].empty())
        out<<"none"<<endl;
    else {
        for (int i = 0; i < map[num].size(); i++) {
            if (map[num][i].first == key) {
                out << map[num][i].second << endl;
                return;
            }
        }
        out<<"none"<<endl;
    }
 
}
void del(string key,  vector<pair<string,string>> *map){
    long long int num=number(key);
    if (map[num].empty())
        return;
    else
        for (int i = 0; i < map[num].size(); i++) {
            if (map[num][i].first == key) {
                map[num].erase(map[num].begin()+i);
                return;
            }
        }
}
int main() {
    vector<pair<string,string>> map[150000];
    while (!inp.eof()) {
        string command;
        inp >> command;
        if (command=="put"){
            string val;
            string key;
            inp >> key >> val;
            put(key,val,map);
        }
        if (command=="get"){
            string key;
            inp >> key;
            get(key,map);
        }
        if (command=="delete"){
            string key;
            inp >> key;
            del(key,map);
        }
    }
    return 0;
}
