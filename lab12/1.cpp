#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> nums;
vector<int> dist;
vector<int> anc;
 
 
void sequence(int max, int maxnum) {
    if (max > 1) {
        sequence(max - 1, anc[maxnum]);
    }
    cout << nums[maxnum] << " ";
}
 
int main() {
    int n;
    int max = 0;
    int maxnum = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    dist.resize(n, 0);
    anc.resize(n, -1);
    for (int i = 0; i < n; i++) {
        dist[i] = 1;
        for (int j = 0; j < n; j++) {
            if (nums[j] < nums[i]) {
                dist[i] = std::max(dist[i], dist[j] + 1);
                if (dist[i] == dist[j] + 1)
                    anc[i] = j;
                if (max < dist[i]) {
                    max = dist[i];
                    maxnum = i;
                }
            }
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        cout << nums[0] << endl;
    } else {
        cout << max << endl;
        sequence(max, maxnum);
    }
    return 0;
}
