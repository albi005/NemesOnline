// ?/100

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int n;
vector<int> boys;
vector<int> girls;

struct Train {
    int boys;
    int girls;
};

int something(int stopIndex, Train train, int money) {
    if (stopIndex == n) {
        return money;
    }

    Train boysTrain = train;
    boysTrain.girls = 0;
    boysTrain.boys += boys[stopIndex];
    int boyMoney = something(stopIndex + 1, boysTrain, money + boysTrain.boys);

    Train girlsTrain = train;
    girlsTrain.boys = 0;
    girlsTrain.girls += girls[stopIndex];
    int girlMoney = something(stopIndex + 1, girlsTrain, money + girlsTrain.girls);

    return max(boyMoney, girlMoney);
}

int main() {
    cin >> n;

    boys.resize(n);
    for (int i = 0; i < n; i++)
        cin >> boys[i];

    girls.resize(n);
    for (int i = 0; i < n; i++)
        cin >> girls[i];

    int result = something(0, {0, 0}, 0);
    cout << result << endl;
}
