// 25/100

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct Range
{
    int start;
    int end;
};

int main()
{
    int pieceCount, cutCount;
    cin >> pieceCount >> cutCount;
    unordered_map<int, Range*> startToRange;
    unordered_map<int, Range*> endToRange;

    Range* first = new Range();
    first->start = -1;
    first->end = -1;
    startToRange[-1] = first;

    Range* last = new Range();
    last->start = pieceCount;
    last->end = pieceCount;
    endToRange[pieceCount] = last;

    int partCount = 1;
    for (int i = 0; i < cutCount; i++)
    {
        Range* cut = new Range();
        cin >> cut->start >> cut->end;

        auto prev = endToRange.find(cut->start - 1);
        if (prev != endToRange.end())
        {
            cut->start = prev->second->start;
            delete prev->second;
            endToRange.erase(prev);
            partCount--;
        }

        auto next = startToRange.find(cut->end + 1);
        if (next != startToRange.end())
        {
            cut->end = next->second->end;
            delete next->second;
            startToRange.erase(next);
            partCount--;
        }

        partCount++;

        startToRange[cut->start] = cut;
        endToRange[cut->end] = cut;

        cout << partCount << "\n";
    }
}
