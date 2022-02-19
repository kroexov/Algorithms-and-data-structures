#include <string>
#include <iostream>
using namespace std;
 
int main()
{
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    float n{};
    int numb;
    float sorted[10000][2];
    cin >> numb;
    int kol = 0;
    double swap1, swap2;
    do
    {
        cin >> n;
        sorted[kol][0] = n;
        sorted[kol][1] = kol+1;
        kol++;
    } while (kol != numb);
    for (int i = 0; i < numb - 1; i++) {
        for (int j = 0; j < numb - 1; j++) {
            if (sorted[j + 1][0] < sorted[j][0])
            {
                swap1 = sorted[j + 1][0];
                sorted[j + 1][0] = sorted[j][0];
                sorted[j][0] = swap1;
                swap2 = sorted[j + 1][1];
                sorted[j + 1][1] = sorted[j][1];
                sorted[j][1] = swap2;
            }
        }
    }
    cout << sorted[0][1] << ' ' << sorted[(numb-1) / 2][1] << ' ' << sorted[numb-1][1] << endl;
}
