#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
const long long limit = 100000000000000;
 
vector <vector <long long>> graph;
vector <long long> distances;
vector <bool> visited;
long long vertexNum, start, finish;
 
void dijkstra() {
    distances[start - 1] = 0;
    for (long long i = 0; i < vertexNum; i++) {
        long long vertex = -1;
        for (long long j = 0; j < vertexNum; j++)
            if (!visited[j] && (vertex == -1 || distances[j] < distances[vertex]))
                vertex = j;
        if (distances[vertex] == limit)
            break;
        visited[vertex] = true;
        for (long long j = 0; j < vertexNum; j++)
            distances[j] = min(distances[j], distances[vertex] + graph[vertex][j]);
    }
}
 
int main()
{
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
    fin >> vertexNum >> start >> finish;
    graph.resize(vertexNum, vector <long long>(vertexNum, limit));
    distances.resize(vertexNum, limit);
    visited.resize(vertexNum);
    for (long long i = 0; i < vertexNum; i++) {
        for (long long j = 0; j < vertexNum; j++) {
            fin >> graph[i][j];
            if (graph[i][j] < 0)
                graph[i][j] = limit;
        }
    }
    dijkstra();
    if (distances[finish - 1] >= limit)
        fout << -1;
    else
        fout << distances[finish - 1];
    return 0;
}
