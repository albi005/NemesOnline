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

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> numToIndex;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numToIndex[num] = i;
    }

    int count = 1;
    int prevIndex = numToIndex[1];

    for (int i = 2; i <= n; i++) {
        if (numToIndex[i] < prevIndex)
            count++;
        prevIndex = numToIndex[i];
    }

    cout << count << endl;
}