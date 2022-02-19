#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define vec vector<string>
 
vec counting_sort(int n, int pos, int C[], vec A) {
    for (int i = 1; i < 255; i++)
        C[i] += C[i - 1];
 
    vec result;
    result.resize(n);
 
    for (int i = n - 1; i >= 0; i--) {
        result[C[A[i][pos]] - 1] = A[i];
        C[A[i][pos]]--;
    }
 
    return result;
}
 
vec radix_sort(int n, int m, int k, vec A) {
    for (int i = m - 1; i >= m - k; i--) {
        int C[255];
        for (int& count : C)
            count = 0;
        for (int j = 0; j < n; j++)
            C[A[j][i]]++;
        A = counting_sort(n, i, C, A);
    }
    return A;
}
 
int main()
{
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vec A;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        A.push_back(str);
    }
 
    A = radix_sort(n, m, k, A);
 
    for (string str : A)
        cout << str << endl;
    return 0;
}
