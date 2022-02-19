#include <string>
#include <iostream>
using namespace std;
 
int main()
{
    long long n{};
    long long numb;
    long long sorted[10001];
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
    cin >> numb;
    int kol = 0;
    int swap;
    do
    {
        cin >> n;
        sorted[kol] = n;
        kol++;
    } while (kol!=numb);
    for (int i = 0; i < numb-1; i++) {
        for (int j = 0; j < numb-1; j++) {
            if (sorted[j + 1] < sorted[j])
            {
                swap = sorted[j + 1];
                sorted[j + 1] = sorted[j];
                sorted[j] = swap;
            }
        }
    }
    kol = 0;
    do
    {
        cout << sorted[kol] << ' ';
        kol++;
    } while (kol != numb);
    return 0;
}
