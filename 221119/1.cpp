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

    vector<int> vals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }

    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < k; i++)
    {
        int val = vals[i];
        if (val > max) max = val;
        if (val < min) min = val;
    }

    int minDiff = max - min;
    int minDiffStart = 0;
    for (int i = k; i < n; i++)
    {
        int in = vals[i];
        if (in > max) max = in;
        if (in < min) min = in;

        int out = vals[i - k];
        if (out == min) {
            min = INT32_MAX;
            for (int j = i - k + 1; j <= i; j++)
            {
                int val = vals[j];
                if (val < min) min = val;
            }
        }
        if (out == max) {
            max = INT32_MIN;
            for (int j = i - k + 1; j <= i; j++)
            {
                int val = vals[j];
                if (val > max) max = val;
            }
        }

        if ((max - min) < minDiff){
            minDiff = max - min;
            minDiffStart = i - k + 1;
        }
    }

    cout << minDiff << "\n" << minDiffStart + 1 << "\n";
}
