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
    int dayCount, nationCount, span;
    cin >> dayCount >> nationCount >> span;
    vector<int> days(dayCount);
    for (size_t i = 0; i < dayCount; i++)
    {
        cin >> days[i];
    }

    unordered_map<int, int> counter;

    int min = INT32_MAX;
    int start;
    for (size_t i = 0; i < dayCount; i++)
    {
        int added = days[i];
        if (added != 0){
            if (counter.count(added) == 0)
                counter[added] = 1;
            else
                counter[added]++;
        }

        if (i < span - 1)
            continue;

        if (counter.size() < min)
        {
            min = counter.size();
            start = i + 1 - span;
        }

        int removed = days[i - span + 1];
        if (removed != 0){
            counter[removed]--;
            if (counter[removed] == 0)
            {
                counter.erase(removed);
            }
        }
    }

    cout << start + 1 << "\n";
}
