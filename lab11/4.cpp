#include <fstream>
#include <vector>
 
const long long limit = 9e18;
 
using namespace std;
 
 
class edge {
public:
    long long from, to, weight;
};
 
 
vector<vector<long long>> graph(2000);
vector<bool> isvisited(2000);
vector<long long> lengths(2000, limit);
vector<edge> edges;
 
 
void dfs(long long from) {
    isvisited[from] = true;
    for (long long to : graph[from])
        if (!isvisited[to])
            dfs(to);
}
 
int main() {
    ifstream in("path.in");
    ofstream out("path.out");
    long long vertexNum, edgesNum, start;
    in >> vertexNum >> edgesNum >> start;
    for (long long i = 0; i < edgesNum; i++) {
        long long from, to, weight;
        in >> from >> to >> weight;
        edges.push_back({from - 1, to - 1, weight});
        graph[from - 1].push_back(to - 1);
    }
    lengths[start - 1] = 0;
    for (long long i = 0; i < vertexNum; ++i) {
        for (long long j = 0; j < edgesNum; ++j) {
            if (lengths[edges[j].from] < limit) {
                if (lengths[edges[j].to] > lengths[edges[j].from] + edges[j].weight) {
                    lengths[edges[j].to] = max(-limit, lengths[edges[j].from] + edges[j].weight);
                }
            }
        }
    }
    for (int i = 0; i < edgesNum; ++i) {
        if (lengths[edges[i].from] < limit) {
            if (lengths[edges[i].to] > lengths[edges[i].from] + edges[i].weight) {
                    dfs(edges[i].to);
            }
        }
    }
    for (long long i = 0; i < vertexNum; ++i) {
        if (isvisited[i])
            out << "-" << endl;
        else if (lengths[i] == limit)
            out << "*" << endl;
        else
            out << lengths[i] << endl;
    }
    return 0;
}
