#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <stack>

std::vector<int> value;
std::vector<int> right;
std::vector<int> left;
size_t max = 0;

void Visit(int roomIndex, size_t sum){
    if (roomIndex == 0){
        if (sum > max)
            max = sum;
        return;
    }
    if (roomIndex == -1)
        return;
    
    sum += value[roomIndex];
    Visit(left[roomIndex], sum);
    Visit(right[roomIndex], sum);
}

int main()
{
    int roomCount;
    std::cin >> roomCount;
    value.resize(roomCount + 1, 0);
    right.resize(roomCount + 1, 0);
    left.resize(roomCount + 1, 0);
    for (size_t i = 1; i <= roomCount; i++)
        std::cin >> value[i] >> right[i] >> left[i];

    Visit(1, 0);

    std::cout << max << "\n";
}
