#include <iostream>
#include <vector>
#include <fstream>
 
std::ifstream inp("hamiltonian.in");
std::ofstream out("hamiltonian.out");
 
std::vector<bool> visited;
std::vector<std::vector<int>> graphs;
std::vector<int> path;
 
void dfs(int num){
    visited[num]=true;
    for (int i=0; i<graphs[num].size(); i++){
        if (not visited[graphs[num][i]])
            dfs(graphs[num][i]);
    }
    path.push_back(num);
}
 
bool pathmaker(int first, int second){
    for (int i = 0; i < graphs[first].size(); i++)
        if (graphs[first][i] == second)
            return true;
    return false;
}
 
int main() {
    int n, m;
    inp >> n >> m;
    visited.resize(n,false);
    graphs.resize(n);
    for (int i=0; i<m; i++){
        int first, second;
        inp>>first>>second;
        graphs[first-1].push_back(second-1);
    }
 
    for (int i=0; i<n; i++) {
        if (not visited[i])
            dfs(i);
    }
 
    for (int i = n - 1; i > 0; i--) {
        if (!pathmaker(path[i], path[i - 1])) {
            out << "NO";
            return 0;
        }
    }
 
    out<< "YES";
    return 0;
}
