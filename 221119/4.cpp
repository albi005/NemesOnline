#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    set<int> common;
    unordered_map<int, int> prev;
    
    for (int i = 0; i < n; i++)
    {
        int val = v[i];

        if (prev.count(val) && i - prev[val] <= k) common.insert(val);

        prev[val] = i;
    }

    vector<int> yep(common.begin(), common.end());
    sort(yep.begin(), yep.end());
    cout << yep.size() << "\n";
    for (int i = 0; i < yep.size(); i++)
    {
        cout << yep[i] << " ";
    }
    cout << "\n";
}
