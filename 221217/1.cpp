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
    int n, first;
    cin >> n >> first;
    int below = INT32_MIN;
    int above = INT32_MAX;
    vector<int> belows;
    vector<int> aboves;
    for (int i = 1; i < n; i++)
    {
        int val;
        cin >> val;

        if (val >= below && val < first)
        {
            belows.push_back(i + 1);
            below = val;
        }
        else if (val <= above && val > first){
            aboves.push_back(i + 1);
            above = val;
        }
    }

    cout << aboves.size() << "\n";
    for (int i = 0; i < aboves.size(); i++)
        cout << aboves[i] << " ";
    cout << "\n";

    cout << belows.size() << "\n";
    for (int i = 0; i < belows.size(); i++)
        cout << belows[i] << " ";
    cout << "\n";
}
