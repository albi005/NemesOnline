// 100/100

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct Stop
{
    int prev = -1;
    int cost;
    int minSum = INT32_MAX;
};


int main()
{
    int stopCount;
    cin >> stopCount;
    vector<Stop> stops(stopCount);
    for (int i = 0; i < stopCount; i++)
        cin >> stops[i].cost;

    stops[0].minSum = stops[0].cost;
    for (int i = 0; i < stopCount - 1; i++)
    {
        int nextSum = stops[i].minSum + stops[i + 1].cost;
        if (nextSum < stops[i + 1].minSum)
        {
            stops[i + 1].minSum = nextSum;
            stops[i + 1].prev = i;
        }

        if (i + 2 < stopCount)
        {
            nextSum = stops[i].minSum + stops[i + 2].cost;
            if (nextSum < stops[i + 2].minSum)
            {
                stops[i + 2].minSum = nextSum;
                stops[i + 2].prev = i;
            }
        }
    }

    Stop lastStop = stops[stopCount - 1];
    cout << lastStop.minSum << "\n";

    vector<int> path;
    int currentStop = stopCount - 1;
    while (currentStop != -1)
    {
        path.push_back(currentStop);
        currentStop = stops[currentStop].prev;
    }

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] + 1 << " ";
    cout << "\n";
}
