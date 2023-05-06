// 15/100

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
    int n, vacationCount, vacationLength;
    cin >> n >> vacationCount >> vacationLength;
    vector<int> sums;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < vacationLength; i++) {
        int temp;
        cin >> temp;
        sum += temp;        
        v.push_back(temp);
    }
    sums.push_back(sum);
    for (int i = vacationLength; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        sum -= v[i - vacationLength];
        sums.push_back(sum);
        v.push_back(temp);

    }

    sort(sums.begin(), sums.end());
    sum = 0;
    for (int i = 0; i < vacationCount; i++)
        sum += sums[i];
    cout << sum << " ";
}