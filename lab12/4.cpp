#include <vector>
#include <fstream>
 
using namespace std;
 
int a[16][16];
int n, m;
 
int horse(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return 0;
    if (a[x][y] != 0) return a[x][y];
    a[x][y] = horse(x - 2, y - 1) + horse(x - 2, y + 1) + horse(x - 1, y - 2) + horse(x + 1, y - 2);
    return a[x][y];
}
 
int main() {
    ifstream in("knight2.in");
    ofstream out("knight2.out");
    in >> n >> m;
    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= m; y++)
            a[x][y] = 0;
 
    a[1][1] = 1;
    out << horse(n, m);
    return 0;
}
