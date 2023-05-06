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
    int n;
    cin >> n;
    vector<bool> v(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        int val;
        cin >> val;
        v[i] = (bool)val;
    }

    int malom = -1;
    int raktar = -1;
    size_t sum = 0;

    for (int i = 0; i < n; i++)
    {
        malom++;
        raktar++;
        while (!v[malom]) malom++;
        while (v[raktar]) raktar++;
        sum += abs(raktar - malom);
    }

    cout << sum << "\n";
}
