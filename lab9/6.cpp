#include <fstream>
#include <vector>
using namespace std;
 
enum Game {
    lose,
    win
};
 
vector<vector <int>> graphs;
vector<Game> vertex;
vector<bool> visited;
 
void dfs(int from) {
    visited[from] = true;
    Game status = lose;
    for (int i = 0; i < graphs[from].size(); ++i) {
        int to = graphs[from][i];
        if (!visited[to])
            dfs(to);
        if (vertex[to] == lose)
            status = win;
    }
    vertex[from] = status;
}
 
int main() {
    ifstream inp("game.in");
    ofstream out("game.out");
    int n, m, place;
    inp >> n >> m >> place;
    graphs.resize(n);
    vertex.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int first, second;
        inp >> first >> second;
        graphs[first - 1].push_back(second - 1);
    }
    dfs(place - 1);
    if (vertex[place - 1])
        out << "First player wins" << endl;
    else
        out << "Second player wins" << endl;
    return 0;
}
