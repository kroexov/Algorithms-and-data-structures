#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
std::ifstream inp("pathbge1.in");
std::ofstream out("pathbge1.out");
std::vector<int> graphs[30001];
int ranges[30001] = { 0 };
 
void bfs(int num) {
    ranges[1] = 1;
    std::queue<int> qu;
    qu.push(num);
    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        for(int i = 0; i < graphs[cur].size(); i++) {
            int next = graphs[cur][i];
            if(ranges[next] == 0) {
                ranges[next] = ranges[cur] + 1;
                qu.push(next);
            }
        }
    }
}
 
int main() {
    int n,m;
    inp>>n>>m;
    for(int i=0;i<m;i++) {
        int first, second;
        inp >> first >> second;
        graphs[first].push_back(second);
        graphs[second].push_back(first);
    }
    bfs(1);
    for (int i=1;i<=n;i++) {
        out << ranges[i]-1 << " ";
    }
 
    return 0;
}
