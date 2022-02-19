#include <fstream>
#include <vector>
using namespace std;
 
enum Color {
    white,
    black
};
 
vector<vector <int>> graphs;
vector<Color> colors;
bool bipartite = true;
 
Color reverse(Color color){
    if (color)
        return white;
    else
        return black;
}
 
void dfs(int from, Color vertexColor) {
    colors[from] = vertexColor;
    for (int i = 0; i < graphs[from].size(); i++) {
        int to = graphs[from][i];
        if (colors[to] == white)
            dfs(to, reverse(vertexColor));
        else if (colors[to] == vertexColor){
            bipartite = false;
            return;
        }
    }
}
 
int main() {
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    int n, m;
    fin >> n >> m;
    graphs.resize(n);
    colors.resize(n, white);
    for (int i = 0; i < m; i++) {
        int first, second;
        fin >> first >> second;
        graphs[first - 1].push_back(second - 1);
        graphs[second - 1].push_back(first - 1);
    }
    for (int i = 0; i < n; i++)
        if (colors[i] == white) {
            dfs(i, white);
            if (!bipartite) {
                fout << "NO";
                return 0;
            }
        }
    fout << "YES";
    fin.close();
    fout.close();
    return 0;
}
