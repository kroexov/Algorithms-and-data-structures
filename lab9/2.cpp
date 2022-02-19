#include <iostream>
#include <fstream>
#include <vector>
std::ifstream inp("cycle.in");
std::ofstream out("cycle.out");
 
int cycleStart = -1, cycleEnd;
 
enum Color{
    white,
    gray,
    black
};
 
bool dfs(int& from, std::vector<std::vector<int>>& graphs, std::vector<Color>& colors, std::vector<int>& parents) {
    colors[from] = gray;
    for (int i = 0; i < graphs[from].size(); i++) {
        int to = graphs[from][i];
        if (colors[to] == white) {
            parents[to] = from;
            if (dfs(to, graphs, colors, parents))
                return true;
        }
        else if (colors[to] == gray) {
            cycleStart = to;
            cycleEnd = from;
            return true;
        }
    }
    colors[from] = black;
    return false;
}
 
int main() {
    int n,m;
    inp>>n>>m;
    std::vector<Color> colors (n,white);
    std::vector<std::vector <int>> graphs (n);
    std::vector<int> parents(n, -1);
    for (int i=0;i<m;i++){
        int first,second;
        inp>>first>>second;
        graphs[first-1].push_back(second-1);
        if (first == second) {
            out << "YES\n" << first;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (colors[i] == white && dfs(i, graphs, colors, parents))
            break;
    }
    if (cycleStart != -1) {
        out << "YES" << std::endl;
        std::vector<int> way;
        for (int cycleNow = cycleEnd; cycleNow != cycleStart; cycleNow = parents[cycleNow])
            way.push_back(cycleNow);
        way.push_back(cycleStart);
        for (int i = way.size() - 1; i >= 0; i--)
            out << way[i] + 1 << " ";
    }
    else
        out << "NO";
    return 0;
}
