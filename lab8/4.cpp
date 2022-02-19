#include <iostream>
#include <fstream>
#include <vector>
std::ifstream inp("components.in");
std::ofstream out("components.out");
std::vector<std::vector<int>> komponents;
std::vector<int> graphs[100000];
int unsearched[100000] = { 0 };
int outer[100000];
 
 
void kompmaker(int number,int komp){
    unsearched[number]=1;
    komponents[komp].push_back(number);
    for (int i=0;i<graphs[number].size();i++){
        if (unsearched[graphs[number][i]]==0)
            kompmaker(graphs[number][i],komp);
    }
}
 
int main() {
    int n,m;
    inp>>n>>m;
    int komp=-1;
    for(int i=0;i<m;i++) {
        int first, second;
        inp >> first >> second;
        graphs[first - 1].push_back(second - 1);
        graphs[second - 1].push_back(first - 1);
    }
    for (int i=0;i<n;i++) {
        if (unsearched[i] == 0) {
            komp += 1;
            komponents.emplace_back(std::vector<int>());
            kompmaker(i, komp);
        }
    }
    out<<komponents.size()<<std::endl;
    for(int i=0;i<komponents.size();i++) {
        for (int j = 0; j < komponents[i].size(); j++) {
            outer[komponents[i][j]] = i + 1;
        }
    }
    for (int i=0;i<n;i++) {
        out << outer[i] << " ";
    }
    return 0;
}
