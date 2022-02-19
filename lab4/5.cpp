#include <iostream>
#include <fstream>
 
using namespace std;
 
int bsearch(int alist[], int left, int right, int key) {
    int mid = (left + right) / 2;
    if (left == mid && alist[mid] != key) {
        return -1;
    }
    if (alist[mid] == key) {
        if (mid > 0 && alist[mid] == alist[mid - 1]) {
            return bsearch(alist, left, mid, key);
        }
        else {
            return mid;
        }
    }
    else {
        if (key > alist[mid]) {
            return bsearch(alist, mid, right, key);
        }
        else {
            return bsearch(alist, left, mid, key);
        }
    }
}
 
    int main(){
        ifstream inp("binsearch.in");
        ofstream out("binsearch.out");
 
        int n;
        inp >> n;
        int a[n];
 
        for (int i = 0; i < n; i++) {
            inp >> a[i];
        }
        int m;
        inp >> m;
        for (int i = 0; i < m; i++) {
            int key;
            inp >> key;
            int low=bsearch(a, 0, n-1, key);
            if (low == -1) {
                out << -1 << ' ' << -1 << endl;
            }
            else {
                int high = low;
                while (high < n and a[high] == key) {
                    high++;
                }
                out << low+1 << ' ' << high << endl;
            }
        }
 
        inp.close();
        out.close();
 
        return 0;
    }
