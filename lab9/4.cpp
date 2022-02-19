#include <iostream>
#include <vector>
#include <fstream>
 
std::ifstream inp("cond.in");
std::ofstream out("cond.out");
 
std::vector<std:: vector<int>> parents;
std::vector<std:: vector<int>> graphs;
std::vector<int> numbers;
std::vector<int> colors;
std::vector<bool> visited;
 
int vertexnum = 0;
int colornum=1;
 
void dfs(int num){
    visited[num]=true;
    for (int i=0; i<graphs[num].size(); i++){
        if (not visited[graphs[num][i]])
            dfs(graphs[num][i]);
    }
    vertexnum++;
    numbers.push_back(num);
}
 
void coloring(int num){
    visited[num]=true;
    colors[num]=colornum;
    for (int i=0; i<parents[num].size(); i++){
        if (!visited[parents[num][i]])
            coloring(parents[num][i]);
    }
}
 
int main() {
    int n, m;
    inp >> n >> m;
    parents.resize(n);
    visited.resize(n,false);
    graphs.resize(n);
    colors.resize(n, 0);
    for (int i=0; i<m; i++){
        int first, second;
        inp>>first>>second;
        graphs[first-1].push_back(second-1);
        parents[second-1].push_back(first-1);
    }
    for (int i=0; i<n; i++){
        if (not visited[i])
            dfs(i);
    }
    visited.assign(n, false);
    for (int i=0; i<n; i++){
        if (!visited[numbers[n-1-i]]) {
            coloring(numbers[n-1-i]);
            colornum++;
        }
    }
    out<<colornum-1<<std::endl;
    for (int i=0; i<colors.size(); i++)
        out<<colors[i]<<" ";
    return 0;
}
