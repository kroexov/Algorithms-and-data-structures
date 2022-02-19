#include <iostream>
#include <conio.h>
#include <vector>
 
using namespace std;
 
long long find(vector<int>&mas, int l, int r, int k)
{
    long long x = mas[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (mas[i] < x) i++; while (mas[j] > x) j--;
 
        if (i <= j) { swap(mas[i], mas[j]); i++; j--; }
    } 
    if (l <= k && k <= j) return find(mas,l, j, k);
    if (i <= k && k <= r) return find(mas,i, r, k);
    return mas[k];
}
 
 
int main() {
  
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
 
    int n, k;
 
    cin >> n >> k;
 
    vector<int>mas(n);
    int A, B, C, a1, a2;
 
    cin >> A >> B >> C >> a1 >> a2;
 
    mas[0] = a1;
    mas[1] = a2;
 
    for (int i = 2; i < n; i++) {
        mas[i] = mas[i - 2] * A + mas[i - 1] * B + C;
    }
 
    find(mas, 0, n-1, k);
 
    cout << find(mas, 0, n-1 , k-1);
 
    return 0;
}
