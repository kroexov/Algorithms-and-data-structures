#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
    long long inf = 100000000000;
    cin >> n;
    vector<int> nums(n + 1);
    vector<int> prev(n + 1);
    vector<int> dist(n + 1);
    vector<int> pos(n + 1);
    vector<int> path;
    int length = 0, j;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    dist[0] = -inf;
    for (int i = 1; i < n + 1; i++){
        dist[i] = inf;
    }
    for (int i = 0; i < n; i++){
        j = int(upper_bound(dist.begin(), dist.end(), nums[i]) - dist.begin());
        if (dist[j - 1] < nums[i] && nums[i] < dist[j]){
            dist[j] = nums[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = max(length, j);
        }
    }
    j = pos[length];
    for (int i = 0; i < length; i++){
        path.push_back(nums[j]);
        j = prev[j];
    }
    cout << length << endl;
    reverse(path.begin(), path.end());
    for (int i : path){
        cout << i << " ";
    }
    return 0;
}
