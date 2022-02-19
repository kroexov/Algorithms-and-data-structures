#include <iostream>
#include<algorithm>
#include <vector>
 
using namespace std;
 
long long n, root;
vector<vector<long long>> graph, dp;
 
void counter(long long v) {
    for (auto e : graph[v]) {
        counter(e);
    }
    if (graph[v].empty()) {
        dp[v][0] = 0;
        dp[v][1] = 1;
    }
    else {
        long long sum1 = 0, sum0 = 0;
        for (auto e : graph[v]) {
            sum1 += max(dp[e][0], dp[e][1]);
            sum0 += dp[e][0];
        }
        dp[v][0] = sum1;
        dp[v][1] = sum0 + 1;
    }
}
 
int main() {
    cin >> n;
    graph.resize(n + 2);
    dp.resize(n + 2, vector<long long>(2, 0));
    for (long long i = 1; i < n + 1; i++) {
        long long x;
        cin >> x;
        if (!x) {
            root = i;
        }
        else {
            graph[x].push_back(i);
        }
    }
    counter(root);
    cout << max(dp[root][0], dp[root][1]);
 
    return 0;
}
