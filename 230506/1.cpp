// 100/100

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Result {
    int count;
    int first;
    int last;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<Result> results;
    for (int first = 0; first < n; first++) {
        int sum = 0;
        for (int last = first; last < n; last++) {
            sum += v[last];
            if (sum % k == 0) {
                results.push_back({last - first + 1, first, last});
                break;
            }
        }
    }

    Result shortest = results[0];
    for (int i = 1; i < results.size(); i++)
        if (results[i].count < shortest.count)
            shortest = results[i];

    cout << shortest.count << endl;
    cout << shortest.first + 1 << " " << shortest.last + 1 << endl;
}