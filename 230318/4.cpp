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

int main()
{
    int heightCount, k;
    cin >> heightCount >> k;

    vector<int> heights(heightCount);
    for (int i = 0; i < heightCount; i++)
        cin >> heights[i];

    vector<int> spans;
    spans.push_back(1);
    int span = 0;
    for (int i = 1; i < heightCount - 1; i++)
    {
        bool isPeak = heights[i] > heights[i - 1] && heights[i] > heights[i + 1];
        if (isPeak)
        {
            span++;
            spans.push_back(0);
        }
        else
            spans[span]++;
    }
    spans[span]++;

    int adventures = 0;
    for (int i = 0; i < spans.size() - k; i++)
    {
        adventures += spans[i] * spans[i + k];
        adventures %= 2023;
    }

    if (adventures == 0) adventures = -1;
    cout << adventures << "\n";
}
