#include <iostream>
#include <vector>
 
using namespace std;
 
int n;
vector<long long> T_shirt;
vector<vector<long long> > variants;
 
int main() {
    cin >> n;
    T_shirt.resize(n);
    variants.resize(n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++) {
        cin >> T_shirt[i];
        variants[i][i] = 1;
    }
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            if (T_shirt[j] == T_shirt[j + i])
                variants[j][j + i] = (variants[j + 1][j + i] % 1000000000 + variants[j][j + i - 1] % 1000000000 + 1) % 1000000000;
            else
                variants[j][j + i] = (variants[j + 1][j + i] % 1000000000 + variants[j][j + i - 1] % 1000000000 - variants[j + 1][j + i - 1] % 1000000000) % 1000000000;
        }
    }
    cout << (variants[0][n - 1] + 1000000000) % 1000000000;
    return 0;
}
