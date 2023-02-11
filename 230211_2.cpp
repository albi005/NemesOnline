// 90/100
// Created using GitHub Copilot

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
    ios_base::sync_with_stdio(false);

    int rowCount, colCount, k;
    cin >> rowCount >> colCount >> k;

    vector<vector<int>> cols(colCount, vector<int>(rowCount));
    for (int y = 0; y < rowCount; y++)
    {
        for (int x = 0; x < colCount; x++)
        {
            cin >> cols[x][y];
        }
    }

    // find a k*k square where the minimum value is the highest and print the coordinates of the top left corner
    int maxMin = 0;
    int maxX = 0;
    int maxY = 0;
    for (int y = 0; y < rowCount - k + 1; y++)
    {
        for (int x = 0; x < colCount - k + 1; x++)
        {
            int min = 1000000000;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (cols[x + i][y + j] < min)
                    {
                        min = cols[x + i][y + j];
                    }
                }
            }

            if (min > maxMin)
            {
                maxMin = min;
                maxX = x;
                maxY = y;
            }
        }
    }

    cout << maxY + 1 << " " << maxX + 1 << endl;
}
