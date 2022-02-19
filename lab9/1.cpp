#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
std::ifstream inp("topsort.in");
std::ofstream out("topsort.out");
 
 
enum Color{
    white,
    gray,
    black
};
 
std::vector<std::vector <int>> orientated;
std::vector<Color> visited;
std::vector<int> topsort;
bool topsortable=true;
 
void dfsv(int num){
    visited[num]=gray;
    for (int i=0; i<orientated[num].size(); i++){
        if (visited[orientated[num][i]]==white)
            dfsv(orientated[num][i]);
        if (visited[orientated[num][i]]==gray) {
            topsortable = false;
            return;
        }
    }
    visited[num] = black;
    topsort.push_back(num);
}
 
void dfs()  {
    for (int i = 1; i < orientated.size(); i++)
        visited[i] = white;
    topsort.clear();
    for (int i = 1; i < orientated.size(); i++)
        if (visited[i] == white)
            dfsv(i);
}
 
int main() {
    int n,m;
    inp>>n>>m;
    orientated.resize(n + 1);
    visited.resize(n + 1);
    topsort.resize(n + 1);
    for (int i=0;i<m;i++){
        int first,second;
        inp>>first>>second;
        orientated[first].push_back(second);
    }
    dfs();
    if (not topsortable)
        out<<-1;
    else {
        for (int i=topsort.size()-1;i>=0;i--){
            out<<topsort[i]<<" ";
        }
    }
    return 0;
}
