#include <vector>
#include <iostream>
#include <algorithm>
#define INT_MAX 0x7fffffff
using namespace std;

int numOfRows, species, k;
vector<int> rows;
vector<int> speciesToCount(species);
int best = INT_MAX;
int back = 0;
int front = 0;

void CheckForBetter() {
    if (front - back < best) best = front - back;
}

bool IsGood() {
    for (int i = 1; i < species; i++) {
        if (speciesToCount[i] < k) return false;
    }
    CheckForBetter();
    return true;
}

bool CanExpand() {
    return front < numOfRows - 1;
}

bool CanShrink() {
    return back < (numOfRows - species * k) - 1;
}

// Returns true if it can't find a good solution
bool ExpandUntilGood() {
    while (CanExpand()) {
        front++;
        int newRow = rows[front];
        speciesToCount[newRow]++;

        if (IsGood()) return false;
    }
    return true;
}

bool ShrinkUntilNotGood() {
    while (CanShrink())
    {
        back++;
        int lostRow = rows[back];
        speciesToCount[lostRow]--;

        if (speciesToCount[lostRow] < k) {
            return false;
        }

        CheckForBetter();
    }

    return true;
}

int main() {

    cin >> numOfRows >> species >> k;
    rows.resize(numOfRows);
    speciesToCount.resize(species + 1);
    for (int i = 0; i < numOfRows; i++)
        cin >> rows[i];

    while (!ExpandUntilGood() && !ShrinkUntilNotGood())
    {
    }

    if (best == INT_MAX) cout << 0;
    else cout << best;

    // Expand one, then shrink
    // - If good, check and loop
    // - If bad, expand until good, loop

    cout << endl;
}