#include <iostream>
#include<algorithm>
#include <vector>
#include <fstream>
 
using namespace std;
 
long long n, root;
vector<vector<long long>> graph, dp;
vector <long long> weight;
 
void algorithm(long long v) {
    for (auto e : graph[v]) {
        algorithm(e);
    }
    if (graph[v].empty()) {
        dp[v][0] = 0;
        dp[v][1] = weight[v];
    }
    else {
        long long sum1 = 0, sum0 = 0;
        for(auto e: graph[v]) {
            sum1 += max(dp[e][0], dp[e][1]);
            sum0 += dp[e][0];
        }
        dp[v][0] = sum1;
        dp[v][1] = sum0 + weight[v];
    }
}
 
int main() {
    ifstream in("selectw.in");
    ofstream out("selectw.out");
    in >> n;
    graph.resize(n + 2);
    weight.resize(n + 2);
    dp.resize(n + 2, vector<long long>(2, 0));
    for (long long i = 1; i < n + 1; i++) {
        long long x;
        in >> x >> weight[i];
        if (!x) {
            root = i;
        }
        else {
            graph[x].push_back(i);
        }
    }
    algorithm(root);
    out << max(dp[root][0], dp[root][1]);
 
    return 0;
}
