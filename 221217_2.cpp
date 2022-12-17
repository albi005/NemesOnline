#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> lastIndex(k, -1);
    vector<int> maxDist(k, INT32_MIN);
    int val;
    for (size_t i = 0; i < n; i++)
    {
        cin >> val;
        val--;

        if (lastIndex[val] != -1)
        {
            int dist = i - lastIndex[val];
            if (dist > maxDist[val])
                maxDist[val] = dist;
        }

        lastIndex[val] = i;
    }

    int min = INT32_MAX;
    int minVal = -1;
    for (size_t i = 0; i < k; i++)
    {
        int val = maxDist[i];
        if (val != INT32_MIN && val < min){
            min = val;
            minVal = i + 1;
        }
    }
    
    cout << minVal << "\n";
}
