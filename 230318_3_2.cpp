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
    int pieceCount, cutCount;
    cin >> pieceCount >> cutCount;
    unordered_set<int> ends;

    ends.insert(0);
    ends.insert(pieceCount + 1);

    int partCount = 1;
    for (int i = 0; i < cutCount; i++)
    {
        int start, end;
        cin >> start >> end;

        if (ends.count(start - 1))
            partCount--;

        if (ends.count(end + 1))
            partCount--;

        partCount++;

        cout << partCount << "\n";

        ends.insert(start);
        ends.insert(end);
    }
}
