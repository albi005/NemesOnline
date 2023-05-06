// 10/100

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
    int sum;
    int first;
    int last;
};

bool overlap(const Result& a, const Result& b)
{
    return a.first <= b.first && b.first <= a.last ||
        a.first <= b.last && b.last <= a.last ||
        b.first <= a.first && a.first <= b.last ||
        b.first <= a.last && a.last <= b.last;
}

int main()
{
    int n, vacationCount, vacationLength;
    cin >> n >> vacationCount >> vacationLength;
    vector<Result> sums;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < vacationLength; i++) {
        int temp;
        cin >> temp;
        sum += temp;        
        v.push_back(temp);
    }
    sums.push_back({ sum, 0, vacationLength - 1 });
    for (int i = vacationLength; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        sum -= v[i - vacationLength];
        sums.push_back({ sum, i - vacationLength + 1, i });
        v.push_back(temp);

    }

    sort(sums.begin(), sums.end(), [](const Result& a, const Result& b) {
        return a.sum < b.sum;
    });

    sum = 0;
    for (int i = 0; i < vacationCount; i++) {
        sum += sums[i].sum;
        if (i < sums.size() - 1 && overlap(sums[i], sums[i + 1])) {
            i++;
        }
    }
    cout << sum << " ";
}