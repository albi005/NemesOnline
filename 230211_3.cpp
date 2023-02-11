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

int main()
{
    ios_base::sync_with_stdio(false);

    int pairCount;
    cin >> pairCount;

    vector<int> cityToMine(pairCount);
    vector<int> mineToCity(pairCount);
    for (int i = 0; i < pairCount; i++)
    {
        int mine;
        cin >> mine;
        mine--;
        cityToMine[i] = mine;
        mineToCity[mine] = i;
    }

    int routeCount = 0;
    int maxRouteCount = 0;
    int maxRouteCountIndex = 0;
    for (int i = 0; i < pairCount; i++)
    {
        int mine = cityToMine[i];
        if (mine > i) {
            routeCount++;
        } else if (mine < i) {
            routeCount--;
        }

        int city = mineToCity[i];
        if (city > i) {
            routeCount++;
        } else if (city < i) {
            routeCount--;
        }

        if (routeCount > maxRouteCount) {
            maxRouteCount = routeCount;
            maxRouteCountIndex = i;
        }
    }
    
    cout << maxRouteCount << endl;
    cout << maxRouteCountIndex + 1 << endl;
}
