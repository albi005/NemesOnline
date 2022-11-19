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
    int n, first;
    cin >> n >> first;
    int below = INT32_MIN;
    int above = INT32_MAX;
    vector<int> results;
    for (int i = 1; i < n; i++)
    {
        int val;
        cin >> val;

        if (val < below)
            results.push_back(i + 1);
        else if (val > above)
            results.push_back(i + 1);
        else if (val != first){
            if (val < first) below = val;
            else above = val;
        }
    }

    cout << results.size() << "\n";
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
    }
    cout << "\n";
}
