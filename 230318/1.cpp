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
    int godorCount;
    cin >> godorCount;
    vector<int> godors(godorCount);
    for (int i = 0; i < godorCount; i++)
        cin >> godors[i];

    int jumpCount;
    cin >> jumpCount;
    vector<int> jumps(jumpCount);
    for (int i = 0; i < jumpCount; i++)
        cin >> jumps[i];

    int lastGodor = godors[godorCount - 1];
    int roadSize = lastGodor + jumps[jumpCount - 1];
    vector<int> prevIndexes(roadSize, -1);

    int currentPos = 0;
    int nextGodorIndex = 1;
    int prevGodor = godors[0];
    int nextGodor = godors[1];
    while (true)
    {
        for (int i = 0; i < jumpCount; i++)
        {
            int nextPos = currentPos + jumps[i];
            if (nextPos <= prevGodor || nextPos >= nextGodor)
                continue;
            if (prevIndexes[nextPos] != -1)
                continue;

            prevIndexes[nextPos] = currentPos;
        }

        currentPos++;
        while (currentPos < roadSize && prevIndexes[currentPos] == -1)
        {
            if (currentPos == prevGodor) {
                prevGodor = nextGodor;
                nextGodorIndex++;
                if (nextGodorIndex < godorCount)
                    nextGodor = godors[nextGodorIndex];
                else
                    nextGodor = INT32_MAX;
            }
            currentPos++;
        }

        if (currentPos > lastGodor)
        {
            if (currentPos == roadSize) {
                cout << "-1" << "\n";
                return 0;
            }

            vector<int> reverse;
            while (currentPos != 0)
            {
                reverse.push_back(currentPos);
                currentPos = prevIndexes[currentPos];
            }
            
            for (int i = godorCount - 1; i >= 0; i--)
            {
                cout << reverse[i] << " ";
            }

            cout << "\n";
            return 0;
        }
    }
}
