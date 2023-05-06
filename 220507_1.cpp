// TODO/100

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
    int index;
    char value;
};

int main()
{
    int n;
    cin >> n;

    string input;
    cin >> input;
    list<Node> nodes;
    int index = 0;
    for (char value : input) {
        Node node;
        node.index = index;
        node.value = value;
        nodes.push_back(node);
        index++;
    }

    auto it = nodes.begin();
    int sum = 0;
    while (true) {
        auto current = it;
        auto next = ++it;
        if (current->value != next->value) {
            it++;
            sum += next->index - current->index;
            nodes.erase(current);
            nodes.erase(next);
        }

        if (nodes.begin() == nodes.end())
            break;

        if (it == nodes.end() || it == --nodes.end())
            it = nodes.begin();
    }

    cout << sum << "\n";
}